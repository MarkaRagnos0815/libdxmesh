#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <functional>

namespace DxMesh {
struct DXM_FLOAT2 {
    float x = 0;
    float y = 0;
};

struct DXM_FLOAT3 {
    float x = 0;
    float y = 0;
    float z = 0;
};

struct DXM_FLOAT4 {
    float x = 0;
    float y = 0;
    float z = 0;
    float w = 0;
};

//---------------------------------------------------------------------------------
// Mesh Optimization Utilities
void ComputeVertexCacheMissRate(const uint16_t* indices, size_t nFaces, size_t nVerts, size_t cacheSize, float& acmr, float& atvr);
void ComputeVertexCacheMissRate(const uint32_t* indices, size_t nFaces, size_t nVerts, size_t cacheSize, float& acmr, float& atvr);
// Compute the average cache miss ratio and average triangle vertex reuse for the post-transform vertex cache

//---------------------------------------------------------------------------------
// Adjacency Computation
void GenerateAdjacencyAndPointReps(const uint16_t* indices, size_t nFaces, const DXM_FLOAT3* positions, size_t nVerts, float epsilon, uint32_t* pointRep, uint32_t* adjacency);
void GenerateAdjacencyAndPointReps(const uint32_t* indices, size_t nFaces, const DXM_FLOAT3* positions, size_t nVerts, float epsilon, uint32_t* pointRep, uint32_t* adjacency);
// If pointRep is null, it still generates them internally as they are needed for the final adjacency computation

void ConvertPointRepsToAdjacency(const uint16_t* indices, size_t nFaces, const DXM_FLOAT3* positions, size_t nVerts, const uint32_t* pointRep, uint32_t* adjacency);
void ConvertPointRepsToAdjacency(const uint32_t* indices, size_t nFaces, const DXM_FLOAT3* positions, size_t nVerts, const uint32_t* pointRep, uint32_t* adjacency);
// If pointRep is null, assumes an identity

void GenerateGSAdjacency(const uint16_t* indices, size_t nFaces, const uint32_t* pointRep, const uint32_t* adjacency, size_t nVerts, uint16_t* indicesAdj) noexcept;
void GenerateGSAdjacency(const uint32_t* indices, size_t nFaces, const uint32_t* pointRep, const uint32_t* adjacency, size_t nVerts, uint32_t* indicesAdj) noexcept;

// Generates an IB suitable for Geometry Shader using D3D1x_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ

//---------------------------------------------------------------------------------
// Normals, Tangents, and Bi-Tangents Computation

enum CNORM_FLAGS : unsigned long {
    CNORM_DEFAULT = 0x0,
    // Default is to compute normals using weight-by-angle

    CNORM_WEIGHT_BY_AREA = 0x1,
    // Computes normals using weight-by-area

    CNORM_WEIGHT_EQUAL = 0x2,
    // Compute normals with equal weights

    CNORM_WIND_CW = 0x4,
    // Vertices are clock-wise (defaults to CCW)
};

void ComputeNormals(const uint16_t* indices, size_t nFaces, const DXM_FLOAT3* positions, size_t nVerts, CNORM_FLAGS flags, DXM_FLOAT3* normals) noexcept;
void ComputeNormals(const uint32_t* indices, size_t nFaces, const DXM_FLOAT3* positions, size_t nVerts, CNORM_FLAGS flags, DXM_FLOAT3* normals) noexcept;
// Computes vertex normals

void ComputeTangentFrame(
    const uint16_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    const DXM_FLOAT3* normals,
    const DXM_FLOAT2* texcoords,
    size_t nVerts,
    DXM_FLOAT3* tangents,
    DXM_FLOAT3* bitangents) noexcept;
void ComputeTangentFrame(
    const uint32_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    const DXM_FLOAT3* normals,
    const DXM_FLOAT2* texcoords,
    size_t nVerts,
    DXM_FLOAT3* tangents,
    DXM_FLOAT3* bitangents) noexcept;
void ComputeTangentFrame(
    const uint16_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    const DXM_FLOAT3* normals,
    const DXM_FLOAT2* texcoords,
    size_t nVerts,
    DXM_FLOAT4* tangents,
    DXM_FLOAT3* bitangents) noexcept;
void ComputeTangentFrame(
    const uint32_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    const DXM_FLOAT3* normals,
    const DXM_FLOAT2* texcoords,
    size_t nVerts,
    DXM_FLOAT4* tangents,
    DXM_FLOAT3* bitangents) noexcept;
void ComputeTangentFrame(const uint16_t* indices, size_t nFaces, const DXM_FLOAT3* positions, const DXM_FLOAT3* normals, const DXM_FLOAT2* texcoords, size_t nVerts, DXM_FLOAT4* tangents) noexcept;
void ComputeTangentFrame(const uint32_t* indices, size_t nFaces, const DXM_FLOAT3* positions, const DXM_FLOAT3* normals, const DXM_FLOAT2* texcoords, size_t nVerts, DXM_FLOAT4* tangents) noexcept;

// Computes tangents and/or bi-tangents (optionally with handedness stored in .w)

//---------------------------------------------------------------------------------
// Mesh clean-up and validation

enum VALIDATE_FLAGS : unsigned long {
    VALIDATE_DEFAULT = 0x0,

    VALIDATE_BACKFACING = 0x1,
    // Check for duplicate neighbor from triangle (requires adjacency)

    VALIDATE_BOWTIES = 0x2,
    // Check for two fans of triangles using the same vertex (requires adjacency)

    VALIDATE_DEGENERATE = 0x4,
    // Check for degenerate triangles

    VALIDATE_UNUSED = 0x8,
    // Check for issues with 'unused' triangles

    VALIDATE_ASYMMETRIC_ADJ = 0x10,
    // Checks that neighbors are symmetric (requires adjacency)
};

void Validate(const uint16_t* indices, size_t nFaces, size_t nVerts, const uint32_t* adjacency, VALIDATE_FLAGS flags, std::wstring* msgs = nullptr);
void Validate(const uint32_t* indices, size_t nFaces, size_t nVerts, const uint32_t* adjacency, VALIDATE_FLAGS flags, std::wstring* msgs = nullptr);
// Checks the mesh for common problems, return 'S_OK' if no problems were found

void Clean(uint16_t* indices, size_t nFaces, size_t nVerts, uint32_t* adjacency, const uint32_t* attributes, std::vector<uint32_t>& dupVerts, bool breakBowties = false);
void Clean(uint32_t* indices, size_t nFaces, size_t nVerts, uint32_t* adjacency, const uint32_t* attributes, std::vector<uint32_t>& dupVerts, bool breakBowties = false);
// Cleans the mesh, splitting vertices if needed

//---------------------------------------------------------------------------------
// Mesh utilities

void WeldVertices(uint16_t* indices, size_t nFaces, size_t nVerts, const uint32_t* pointRep, uint32_t* vertexRemap, std::function<bool(uint32_t v0, uint32_t v1)> weldTest);
void WeldVertices(uint32_t* indices, size_t nFaces, size_t nVerts, const uint32_t* pointRep, uint32_t* vertexRemap, std::function<bool(uint32_t v0, uint32_t v1)> weldTest);
// Welds vertices together based on a test function

void ConcatenateMesh(size_t nFaces, size_t nVerts, uint32_t* faceDestMap, uint32_t* vertexDestMap, size_t& totalFaces, size_t& totalVerts) noexcept;
// Merge meshes together

//---------------------------------------------------------------------------------
// Mesh Optimization

void AttributeSort(size_t nFaces, uint32_t* attributes, uint32_t* faceRemap);

// Reorders faces by attribute id

enum OPTFACES : uint32_t {
    OPTFACES_V_DEFAULT = 12,
    OPTFACES_R_DEFAULT = 7,
    // Default vertex cache size and restart threshold which is considered 'device independent'

    OPTFACES_LRU_DEFAULT = 32,
    // Default vertex cache size for the LRU algorithm

    OPTFACES_V_STRIPORDER = 0,
    // Indicates no vertex cache optimization, only reordering into strips
};

void OptimizeFaces(const uint16_t* indices, size_t nFaces, const uint32_t* adjacency, uint32_t* faceRemap, uint32_t vertexCache = OPTFACES_V_DEFAULT, uint32_t restart = OPTFACES_R_DEFAULT);
void OptimizeFaces(const uint32_t* indices, size_t nFaces, const uint32_t* adjacency, uint32_t* faceRemap, uint32_t vertexCache = OPTFACES_V_DEFAULT, uint32_t restart = OPTFACES_R_DEFAULT);
void OptimizeFacesLRU(const uint16_t* indices, size_t nFaces, uint32_t* faceRemap, uint32_t lruCacheSize = OPTFACES_LRU_DEFAULT);
void OptimizeFacesLRU(const uint32_t* indices, size_t nFaces, uint32_t* faceRemap, uint32_t lruCacheSize = OPTFACES_LRU_DEFAULT);
// Reorders faces to increase hit rate of vertex caches

void OptimizeFacesEx(
    const uint16_t* indices,
    size_t nFaces,
    const uint32_t* adjacency,
    const uint32_t* attributes,
    uint32_t* faceRemap,
    uint32_t vertexCache = OPTFACES_V_DEFAULT,
    uint32_t restart = OPTFACES_R_DEFAULT);
void OptimizeFacesEx(
    const uint32_t* indices,
    size_t nFaces,
    const uint32_t* adjacency,
    const uint32_t* attributes,
    uint32_t* faceRemap,
    uint32_t vertexCache = OPTFACES_V_DEFAULT,
    uint32_t restart = OPTFACES_R_DEFAULT);
void OptimizeFacesLRUEx(const uint16_t* indices, size_t nFaces, const uint32_t* attributes, uint32_t* faceRemap, uint32_t lruCacheSize = OPTFACES_LRU_DEFAULT);
void OptimizeFacesLRUEx(const uint32_t* indices, size_t nFaces, const uint32_t* attributes, uint32_t* faceRemap, uint32_t lruCacheSize = OPTFACES_LRU_DEFAULT);
// Attribute group version of OptimizeFaces

void OptimizeVertices(const uint16_t* indices, size_t nFaces, size_t nVerts, uint32_t* vertexRemap, size_t* trailingUnused = nullptr) noexcept;
void OptimizeVertices(const uint32_t* indices, size_t nFaces, size_t nVerts, uint32_t* vertexRemap, size_t* trailingUnused = nullptr) noexcept;
// Reorders vertices in order of use

//---------------------------------------------------------------------------------
// Remap functions

void ReorderIB(const uint16_t* ibin, size_t nFaces, const uint32_t* faceRemap, uint16_t* ibout) noexcept;
void ReorderIB(uint16_t* ib, size_t nFaces, const uint32_t* faceRemap) noexcept;
void ReorderIB(const uint32_t* ibin, size_t nFaces, const uint32_t* faceRemap, uint32_t* ibout) noexcept;
void ReorderIB(uint32_t* ib, size_t nFaces, const uint32_t* faceRemap) noexcept;
// Applies a face remap reordering to an index buffer

void ReorderIBAndAdjacency(const uint16_t* ibin, size_t nFaces, const uint32_t* adjin, const uint32_t* faceRemap, uint16_t* ibout, uint32_t* adjout) noexcept;
void ReorderIBAndAdjacency(uint16_t* ib, size_t nFaces, uint32_t* adj, const uint32_t* faceRemap) noexcept;
void ReorderIBAndAdjacency(const uint32_t* ibin, size_t nFaces, const uint32_t* adjin, const uint32_t* faceRemap, uint32_t* ibout, uint32_t* adjout) noexcept;
void ReorderIBAndAdjacency(uint32_t* ib, size_t nFaces, uint32_t* adj, const uint32_t* faceRemap) noexcept;
// Applies a face remap reordering to an index buffer and adjacency

void FinalizeIB(const uint16_t* ibin, size_t nFaces, const uint32_t* vertexRemap, size_t nVerts, uint16_t* ibout) noexcept;
void FinalizeIB(uint16_t* ib, size_t nFaces, const uint32_t* vertexRemap, size_t nVerts) noexcept;
void FinalizeIB(const uint32_t* ibin, size_t nFaces, const uint32_t* vertexRemap, size_t nVerts, uint32_t* ibout) noexcept;
void FinalizeIB(uint32_t* ib, size_t nFaces, const uint32_t* vertexRemap, size_t nVerts) noexcept;
// Applies a vertex remap reordering to an index buffer

void FinalizeVB(const void* vbin, size_t stride, size_t nVerts, const uint32_t* dupVerts, size_t nDupVerts, const uint32_t* vertexRemap, void* vbout) noexcept;
void FinalizeVB(void* vb, size_t stride, size_t nVerts, const uint32_t* vertexRemap) noexcept;
// Applies a vertex remap and/or a vertex duplication set to a vertex buffer

void FinalizeVBAndPointReps(
    const void* vbin,
    size_t stride,
    size_t nVerts,
    const uint32_t* prin,
    const uint32_t* dupVerts,
    size_t nDupVerts,
    const uint32_t* vertexRemap,
    void* vbout,
    uint32_t* prout) noexcept;
void FinalizeVBAndPointReps(void* vb, size_t stride, size_t nVerts, uint32_t* pointRep, const uint32_t* vertexRemap) noexcept;
// Applies a vertex remap and/or a vertex duplication set to a vertex buffer and point representatives

void CompactVB(const void* vbin, size_t stride, size_t nVerts, size_t trailingUnused, const uint32_t* vertexRemap, void* vbout) noexcept;
// Applies a vertex remap which contains a known number of unused entries at the end

//---------------------------------------------------------------------------------
// Meshlet Generation

constexpr size_t MESHLET_DEFAULT_MAX_VERTS = 128u;
constexpr size_t MESHLET_DEFAULT_MAX_PRIMS = 128u;

constexpr size_t MESHLET_MINIMUM_SIZE = 32u;
constexpr size_t MESHLET_MAXIMUM_SIZE = 256u;

enum MESHLET_FLAGS : unsigned long {
    MESHLET_DEFAULT = 0x0,

    MESHLET_WIND_CW = 0x1,
    // Vertices are clock-wise (defaults to CCW)
};

struct Meshlet {
    uint32_t VertCount;
    uint32_t VertOffset;
    uint32_t PrimCount;
    uint32_t PrimOffset;
};

struct MeshletTriangle {
    uint32_t i0 : 10;
    uint32_t i1 : 10;
    uint32_t i2 : 10;
};

void ComputeMeshlets(
    const uint16_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    size_t nVerts,
    const uint32_t* adjacency,
    std::vector<Meshlet>& meshlets,
    std::vector<uint8_t>& uniqueVertexIB,
    std::vector<MeshletTriangle>& primitiveIndices,
    size_t maxVerts = MESHLET_DEFAULT_MAX_VERTS,
    size_t maxPrims = MESHLET_DEFAULT_MAX_PRIMS);
void ComputeMeshlets(
    const uint32_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    size_t nVerts,
    const uint32_t* adjacency,
    std::vector<Meshlet>& meshlets,
    std::vector<uint8_t>& uniqueVertexIB,
    std::vector<MeshletTriangle>& primitiveIndices,
    size_t maxVerts = MESHLET_DEFAULT_MAX_VERTS,
    size_t maxPrims = MESHLET_DEFAULT_MAX_PRIMS);
// Generates meshlets for a single subset mesh

void ComputeMeshlets(
    const uint16_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    size_t nVerts,
    const std::pair<size_t, size_t>* subsets,
    size_t nSubsets,
    const uint32_t* adjacency,
    std::vector<Meshlet>& meshlets,
    std::vector<uint8_t>& uniqueVertexIB,
    std::vector<MeshletTriangle>& primitiveIndices,
    std::pair<size_t, size_t>* meshletSubsets,
    size_t maxVerts = MESHLET_DEFAULT_MAX_VERTS,
    size_t maxPrims = MESHLET_DEFAULT_MAX_PRIMS);
void ComputeMeshlets(
    const uint32_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    size_t nVerts,
    const std::pair<size_t, size_t>* subsets,
    size_t nSubsets,
    const uint32_t* adjacency,
    std::vector<Meshlet>& meshlets,
    std::vector<uint8_t>& uniqueVertexIB,
    std::vector<MeshletTriangle>& primitiveIndices,
    std::pair<size_t, size_t>* meshletSubsets,
    size_t maxVerts = MESHLET_DEFAULT_MAX_VERTS,
    size_t maxPrims = MESHLET_DEFAULT_MAX_PRIMS);
// Generates meshlets for a mesh with several face subsets

}  // namespace DxMesh