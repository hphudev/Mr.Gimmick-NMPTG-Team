#include "TransformHandler.h"

const D3DXMATRIX* TransformHandler::GetScaleMatrix(Pair scale)
{
    D3DXMATRIX scaleMatrix;
    D3DXMatrixScaling(&scaleMatrix, scale.GetFirstValue(), scale.GetSecondValue(), 1);

    return &scaleMatrix;
}