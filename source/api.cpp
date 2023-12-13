
#include "libdxmesh.h"
#include "DirectXMesh.h"
using namespace DirectX;
using namespace DirectX::PackedVector;

namespace DxMesh {
void hr2Exception(HRESULT hr) {
}

//---------------------------------------------------------------------------------
// Mesh Optimization Utilities
void ComputeVertexCacheMissRate(const uint16_t* indices, size_t nFaces, size_t nVerts, size_t cacheSize, float& acmr, float& atvr) {
    DirectX::ComputeVertexCacheMissRate(indices, nFaces, nVerts, cacheSize, acmr, atvr);
}

void ComputeVertexCacheMissRate(const uint32_t* indices, size_t nFaces, size_t nVerts, size_t cacheSize, float& acmr, float& atvr) {
    DirectX::ComputeVertexCacheMissRate(indices, nFaces, nVerts, cacheSize, acmr, atvr);
}

//---------------------------------------------------------------------------------
// Adjacency Computation
void GenerateAdjacencyAndPointReps(const uint16_t* indices, size_t nFaces, const DXM_FLOAT3* positions, size_t nVerts, float epsilon, uint32_t* pointRep, uint32_t* adjacency) {
    hr2Exception(DirectX::GenerateAdjacencyAndPointReps(indices, nFaces, (XMFLOAT3*)positions, nVerts, epsilon, pointRep, adjacency));
}

void GenerateAdjacencyAndPointReps(const uint32_t* indices, size_t nFaces, const DXM_FLOAT3* positions, size_t nVerts, float epsilon, uint32_t* pointRep, uint32_t* adjacency) {
    hr2Exception(DirectX::GenerateAdjacencyAndPointReps(indices, nFaces, (XMFLOAT3*)positions, nVerts, epsilon, pointRep, adjacency));
}

// If pointRep is null, it still generates them internally as they are needed for the final adjacency computation

void ConvertPointRepsToAdjacency(const uint16_t* indices, size_t nFaces, const DXM_FLOAT3* positions, size_t nVerts, const uint32_t* pointRep, uint32_t* adjacency) {
    hr2Exception(DirectX::ConvertPointRepsToAdjacency(indices, nFaces, (XMFLOAT3*)positions, nVerts, pointRep, adjacency));
}

void ConvertPointRepsToAdjacency(const uint32_t* indices, size_t nFaces, const DXM_FLOAT3* positions, size_t nVerts, const uint32_t* pointRep, uint32_t* adjacency) {
    hr2Exception(DirectX::ConvertPointRepsToAdjacency(indices, nFaces, (XMFLOAT3*)positions, nVerts, pointRep, adjacency));
}

// If pointRep is null, assumes an identity
void GenerateGSAdjacency(const uint16_t* indices, size_t nFaces, const uint32_t* pointRep, const uint32_t* adjacency, size_t nVerts, uint16_t* indicesAdj) noexcept {
    hr2Exception(DirectX::GenerateGSAdjacency(indices, nFaces, pointRep, adjacency, nVerts, indicesAdj));
}

void GenerateGSAdjacency(const uint32_t* indices, size_t nFaces, const uint32_t* pointRep, const uint32_t* adjacency, size_t nVerts, uint32_t* indicesAdj) noexcept {
    hr2Exception(DirectX::GenerateGSAdjacency(indices, nFaces, pointRep, adjacency, nVerts, indicesAdj));
}

//---------------------------------------------------------------------------------
// Normals, Tangents, and Bi-Tangents Computation

void ComputeNormals(const uint16_t* indices, size_t nFaces, const DXM_FLOAT3* positions, size_t nVerts, CNORM_FLAGS flags, DXM_FLOAT3* normals) noexcept {
    hr2Exception(DirectX::ComputeNormals(indices, nFaces, (XMFLOAT3*)positions, nVerts, (DirectX::CNORM_FLAGS)flags, (XMFLOAT3*)normals));
}

void ComputeNormals(const uint32_t* indices, size_t nFaces, const DXM_FLOAT3* positions, size_t nVerts, CNORM_FLAGS flags, DXM_FLOAT3* normals) noexcept {
    hr2Exception(DirectX::ComputeNormals(indices, nFaces, (XMFLOAT3*)positions, nVerts, (DirectX::CNORM_FLAGS)flags, (XMFLOAT3*)normals));
}

// Computes vertex normals

void ComputeTangentFrame(
    const uint16_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    const DXM_FLOAT3* normals,
    const DXM_FLOAT2* texcoords,
    size_t nVerts,
    DXM_FLOAT3* tangents,
    DXM_FLOAT3* bitangents) noexcept {
    hr2Exception(DirectX::ComputeTangentFrame(indices, nFaces, (XMFLOAT3*)positions, (XMFLOAT3*)normals, (XMFLOAT2*)texcoords, nVerts, (XMFLOAT3*)tangents, (XMFLOAT3*)bitangents));
}

void ComputeTangentFrame(
    const uint32_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    const DXM_FLOAT3* normals,
    const DXM_FLOAT2* texcoords,
    size_t nVerts,
    DXM_FLOAT3* tangents,
    DXM_FLOAT3* bitangents) noexcept {
    hr2Exception(DirectX::ComputeTangentFrame(indices, nFaces, (XMFLOAT3*)positions, (XMFLOAT3*)normals, (XMFLOAT2*)texcoords, nVerts, (XMFLOAT3*)tangents, (XMFLOAT3*)bitangents));
}

void ComputeTangentFrame(
    const uint16_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    const DXM_FLOAT3* normals,
    const DXM_FLOAT2* texcoords,
    size_t nVerts,
    DXM_FLOAT4* tangents,
    DXM_FLOAT3* bitangents) noexcept {
    hr2Exception(DirectX::ComputeTangentFrame(indices, nFaces, (XMFLOAT3*)positions, (XMFLOAT3*)normals, (XMFLOAT2*)texcoords, nVerts, (XMFLOAT4*)tangents, (XMFLOAT3*)bitangents));
}

void ComputeTangentFrame(
    const uint32_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    const DXM_FLOAT3* normals,
    const DXM_FLOAT2* texcoords,
    size_t nVerts,
    DXM_FLOAT4* tangents,
    DXM_FLOAT3* bitangents) noexcept {
    hr2Exception(DirectX::ComputeTangentFrame(indices, nFaces, (XMFLOAT3*)positions, (XMFLOAT3*)normals, (XMFLOAT2*)texcoords, nVerts, (XMFLOAT4*)tangents, (XMFLOAT3*)bitangents));
}

void ComputeTangentFrame(const uint16_t* indices, size_t nFaces, const DXM_FLOAT3* positions, const DXM_FLOAT3* normals, const DXM_FLOAT2* texcoords, size_t nVerts, DXM_FLOAT4* tangents) noexcept {
    hr2Exception(DirectX::ComputeTangentFrame(indices, nFaces, (XMFLOAT3*)positions, (XMFLOAT3*)normals, (XMFLOAT2*)texcoords, nVerts, (XMFLOAT4*)tangents));
}

void ComputeTangentFrame(const uint32_t* indices, size_t nFaces, const DXM_FLOAT3* positions, const DXM_FLOAT3* normals, const DXM_FLOAT2* texcoords, size_t nVerts, DXM_FLOAT4* tangents) noexcept {
    hr2Exception(DirectX::ComputeTangentFrame(indices, nFaces, (XMFLOAT3*)positions, (XMFLOAT3*)normals, (XMFLOAT2*)texcoords, nVerts, (XMFLOAT4*)tangents));
}

//---------------------------------------------------------------------------------
// Mesh clean-up and validation
void Validate(const uint16_t* indices, size_t nFaces, size_t nVerts, const uint32_t* adjacency, VALIDATE_FLAGS flags, std::wstring* msgs) {
    hr2Exception(DirectX::Validate(indices, nFaces, nVerts, adjacency, (DirectX::VALIDATE_FLAGS)flags, msgs));
}

void Validate(const uint32_t* indices, size_t nFaces, size_t nVerts, const uint32_t* adjacency, VALIDATE_FLAGS flags, std::wstring* msgs) {
    hr2Exception(DirectX::Validate(indices, nFaces, nVerts, adjacency, (DirectX::VALIDATE_FLAGS)flags, msgs));
}

// Checks the mesh for common problems, return 'S_OK' if no problems were found

void Clean(uint16_t* indices, size_t nFaces, size_t nVerts, uint32_t* adjacency, const uint32_t* attributes, std::vector<uint32_t>& dupVerts, bool breakBowties) {
    hr2Exception(DirectX::Clean(indices, nFaces, nVerts, adjacency, attributes, dupVerts, breakBowties));
}

void Clean(uint32_t* indices, size_t nFaces, size_t nVerts, uint32_t* adjacency, const uint32_t* attributes, std::vector<uint32_t>& dupVerts, bool breakBowties) {
    hr2Exception(DirectX::Clean(indices, nFaces, nVerts, adjacency, attributes, dupVerts, breakBowties));
}

//---------------------------------------------------------------------------------
// Mesh utilities

void WeldVertices(uint16_t* indices, size_t nFaces, size_t nVerts, const uint32_t* pointRep, uint32_t* vertexRemap, std::function<bool(uint32_t v0, uint32_t v1)> weldTest) {
    hr2Exception(DirectX::WeldVertices(indices, nFaces, nVerts, pointRep, vertexRemap, weldTest));
}

void WeldVertices(uint32_t* indices, size_t nFaces, size_t nVerts, const uint32_t* pointRep, uint32_t* vertexRemap, std::function<bool(uint32_t v0, uint32_t v1)> weldTest) {
    hr2Exception(DirectX::WeldVertices(indices, nFaces, nVerts, pointRep, vertexRemap, weldTest));
}

void ConcatenateMesh(size_t nFaces, size_t nVerts, uint32_t* faceDestMap, uint32_t* vertexDestMap, size_t& totalFaces, size_t& totalVerts) noexcept {
    hr2Exception(DirectX::ConcatenateMesh(nFaces, nVerts, faceDestMap, vertexDestMap, totalFaces, totalVerts));
}

//---------------------------------------------------------------------------------
// Mesh Optimization

void AttributeSort(size_t nFaces, uint32_t* attributes, uint32_t* faceRemap) {
    hr2Exception(DirectX::AttributeSort(nFaces, attributes, faceRemap));
}

// Reorders faces by attribute id
void OptimizeFaces(const uint16_t* indices, size_t nFaces, const uint32_t* adjacency, uint32_t* faceRemap, uint32_t vertexCache, uint32_t restart) {
    hr2Exception(DirectX::OptimizeFaces(indices, nFaces, adjacency, faceRemap, vertexCache, restart));
}

void OptimizeFaces(const uint32_t* indices, size_t nFaces, const uint32_t* adjacency, uint32_t* faceRemap, uint32_t vertexCache, uint32_t restart) {
    hr2Exception(DirectX::OptimizeFaces(indices, nFaces, adjacency, faceRemap, vertexCache, restart));
}

void OptimizeFacesLRU(const uint16_t* indices, size_t nFaces, uint32_t* faceRemap, uint32_t lruCacheSize) {
    hr2Exception(DirectX::OptimizeFacesLRU(indices, nFaces, faceRemap, lruCacheSize));
}

void OptimizeFacesLRU(const uint32_t* indices, size_t nFaces, uint32_t* faceRemap, uint32_t lruCacheSize) {
    hr2Exception(DirectX::OptimizeFacesLRU(indices, nFaces, faceRemap, lruCacheSize));
}

// Reorders faces to increase hit rate of vertex caches

void OptimizeFacesEx(const uint16_t* indices, size_t nFaces, const uint32_t* adjacency, const uint32_t* attributes, uint32_t* faceRemap, uint32_t vertexCache, uint32_t restart) {
    hr2Exception(DirectX::OptimizeFacesEx(indices, nFaces, adjacency, attributes, faceRemap, vertexCache, restart));
}

void OptimizeFacesEx(const uint32_t* indices, size_t nFaces, const uint32_t* adjacency, const uint32_t* attributes, uint32_t* faceRemap, uint32_t vertexCache, uint32_t restart) {
    hr2Exception(DirectX::OptimizeFacesEx(indices, nFaces, adjacency, attributes, faceRemap, vertexCache, restart));
}

void OptimizeFacesLRUEx(const uint16_t* indices, size_t nFaces, const uint32_t* attributes, uint32_t* faceRemap, uint32_t lruCacheSize) {
    hr2Exception(DirectX::OptimizeFacesLRUEx(indices, nFaces, attributes, faceRemap, lruCacheSize));
}

void OptimizeFacesLRUEx(const uint32_t* indices, size_t nFaces, const uint32_t* attributes, uint32_t* faceRemap, uint32_t lruCacheSize) {
    hr2Exception(DirectX::OptimizeFacesLRUEx(indices, nFaces, attributes, faceRemap, lruCacheSize));
}

// Attribute group version of OptimizeFaces

void OptimizeVertices(const uint16_t* indices, size_t nFaces, size_t nVerts, uint32_t* vertexRemap, size_t* trailingUnused) noexcept {
    hr2Exception(DirectX::OptimizeVertices(indices, nFaces, nVerts, vertexRemap, trailingUnused));
}

void OptimizeVertices(const uint32_t* indices, size_t nFaces, size_t nVerts, uint32_t* vertexRemap, size_t* trailingUnused) noexcept {
    hr2Exception(DirectX::OptimizeVertices(indices, nFaces, nVerts, vertexRemap, trailingUnused));
}

// Reorders vertices in order of use

//---------------------------------------------------------------------------------
// Remap functions

void ReorderIB(const uint16_t* ibin, size_t nFaces, const uint32_t* faceRemap, uint16_t* ibout) noexcept {
    hr2Exception(DirectX::ReorderIB(ibin, nFaces, faceRemap, ibout));
}

void ReorderIB(uint16_t* ib, size_t nFaces, const uint32_t* faceRemap) noexcept {
    hr2Exception(DirectX::ReorderIB(ib, nFaces, faceRemap));
}

void ReorderIB(const uint32_t* ibin, size_t nFaces, const uint32_t* faceRemap, uint32_t* ibout) noexcept {
    hr2Exception(DirectX::ReorderIB(ibin, nFaces, faceRemap, ibout));
}

void ReorderIB(uint32_t* ib, size_t nFaces, const uint32_t* faceRemap) noexcept {
    hr2Exception(DirectX::ReorderIB(ib, nFaces, faceRemap));
}

// Applies a face remap reordering to an index buffer

void ReorderIBAndAdjacency(const uint16_t* ibin, size_t nFaces, const uint32_t* adjin, const uint32_t* faceRemap, uint16_t* ibout, uint32_t* adjout) noexcept {
    hr2Exception(DirectX::ReorderIBAndAdjacency(ibin, nFaces, adjin, faceRemap, ibout, adjout));
}

void ReorderIBAndAdjacency(uint16_t* ib, size_t nFaces, uint32_t* adj, const uint32_t* faceRemap) noexcept {
    hr2Exception(DirectX::ReorderIBAndAdjacency(ib, nFaces, adj, faceRemap));
}

void ReorderIBAndAdjacency(const uint32_t* ibin, size_t nFaces, const uint32_t* adjin, const uint32_t* faceRemap, uint32_t* ibout, uint32_t* adjout) noexcept {
    hr2Exception(DirectX::ReorderIBAndAdjacency(ibin, nFaces, adjin, faceRemap, ibout, adjout));
}

void ReorderIBAndAdjacency(uint32_t* ib, size_t nFaces, uint32_t* adj, const uint32_t* faceRemap) noexcept {
    hr2Exception(DirectX::ReorderIBAndAdjacency(ib, nFaces, adj, faceRemap));
}

// Applies a face remap reordering to an index buffer and adjacency

void FinalizeIB(const uint16_t* ibin, size_t nFaces, const uint32_t* vertexRemap, size_t nVerts, uint16_t* ibout) noexcept {
    hr2Exception(DirectX::FinalizeIB(ibin, nFaces, vertexRemap, nVerts, ibout));
}

void FinalizeIB(uint16_t* ib, size_t nFaces, const uint32_t* vertexRemap, size_t nVerts) noexcept {
    hr2Exception(DirectX::FinalizeIB(ib, nFaces, vertexRemap, nVerts));
}

void FinalizeIB(const uint32_t* ibin, size_t nFaces, const uint32_t* vertexRemap, size_t nVerts, uint32_t* ibout) noexcept {
    hr2Exception(DirectX::FinalizeIB(ibin, nFaces, vertexRemap, nVerts, ibout));
}

void FinalizeIB(uint32_t* ib, size_t nFaces, const uint32_t* vertexRemap, size_t nVerts) noexcept {
    hr2Exception(DirectX::FinalizeIB(ib, nFaces, vertexRemap, nVerts));
}

// Applies a vertex remap reordering to an index buffer

void FinalizeVB(const void* vbin, size_t stride, size_t nVerts, const uint32_t* dupVerts, size_t nDupVerts, const uint32_t* vertexRemap, void* vbout) noexcept {
    hr2Exception(DirectX::FinalizeVB(vbin, stride, nVerts, dupVerts, nDupVerts, vertexRemap, vbout));
}

void FinalizeVB(void* vb, size_t stride, size_t nVerts, const uint32_t* vertexRemap) noexcept {
    hr2Exception(DirectX::FinalizeVB(vb, stride, nVerts, vertexRemap));
}

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
    uint32_t* prout) noexcept {
    hr2Exception(DirectX::FinalizeVBAndPointReps(vbin, stride, nVerts, prin, dupVerts, nDupVerts, vertexRemap, vbout, prout));
}

void FinalizeVBAndPointReps(void* vb, size_t stride, size_t nVerts, uint32_t* pointRep, const uint32_t* vertexRemap) noexcept {
    hr2Exception(DirectX::FinalizeVBAndPointReps(vb, stride, nVerts, pointRep, vertexRemap));
}

void CompactVB(const void* vbin, size_t stride, size_t nVerts, size_t trailingUnused, const uint32_t* vertexRemap, void* vbout) noexcept {
    hr2Exception(DirectX::CompactVB(vbin, stride, nVerts, trailingUnused, vertexRemap, vbout));
}

void ComputeMeshlets(
    const uint16_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    size_t nVerts,
    const uint32_t* adjacency,
    std::vector<Meshlet>& meshlets,
    std::vector<uint8_t>& uniqueVertexIB,
    std::vector<MeshletTriangle>& primitiveIndices,
    size_t maxVerts,
    size_t maxPrims) {
    hr2Exception(DirectX::ComputeMeshlets(
        indices,
        nFaces,
        (XMFLOAT3*)positions,
        nVerts,
        adjacency,
        (std::vector<DirectX::Meshlet>&)meshlets,
        uniqueVertexIB,
        (std::vector<DirectX::MeshletTriangle>&)primitiveIndices,
        maxVerts,
        maxPrims));
}

void ComputeMeshlets(
    const uint32_t* indices,
    size_t nFaces,
    const DXM_FLOAT3* positions,
    size_t nVerts,
    const uint32_t* adjacency,
    std::vector<Meshlet>& meshlets,
    std::vector<uint8_t>& uniqueVertexIB,
    std::vector<MeshletTriangle>& primitiveIndices,
    size_t maxVerts,
    size_t maxPrims) {
    hr2Exception(DirectX::ComputeMeshlets(
        indices,
        nFaces,
        (XMFLOAT3*)positions,
        nVerts,
        adjacency,
        (std::vector<DirectX::Meshlet>&)meshlets,
        uniqueVertexIB,
        (std::vector<DirectX::MeshletTriangle>&)primitiveIndices,
        maxVerts,
        maxPrims));
}

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
    size_t maxVerts,
    size_t maxPrims) {
    hr2Exception(DirectX::ComputeMeshlets(
        indices,
        nFaces,
        (XMFLOAT3*)positions,
        nVerts,
        subsets,
        nSubsets,
        adjacency,
        (std::vector<DirectX::Meshlet>&)meshlets,
        uniqueVertexIB,
        (std::vector<DirectX::MeshletTriangle>&)primitiveIndices,
        meshletSubsets,
        maxVerts,
        maxPrims));
}

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
    size_t maxVerts,
    size_t maxPrims) {
    hr2Exception(DirectX::ComputeMeshlets(
        indices,
        nFaces,
        (XMFLOAT3*)positions,
        nVerts,
        subsets,
        nSubsets,
        adjacency,
        (std::vector<DirectX::Meshlet>&)meshlets,
        uniqueVertexIB,
        (std::vector<DirectX::MeshletTriangle>&)primitiveIndices,
        meshletSubsets,
        maxVerts,
        maxPrims));
}

// Generates meshlets for a mesh with several face subsets

}  // namespace DxMesh