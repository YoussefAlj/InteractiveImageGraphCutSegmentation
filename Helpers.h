#ifndef HELPERS_H
#define HELPERS_H

// ITK
#include "itkImage.h"
#include "itkIndex.h"

// VTK
#include <vtkSmartPointer.h>
#include <vtkImageData.h>

// Custom
#include "Types.h"

namespace Helpers
{

void MaskImage(vtkSmartPointer<vtkImageData> VTKImage, vtkSmartPointer<vtkImageData> VTKSegmentMask, vtkSmartPointer<vtkImageData> VTKMaskedImage);

// Mark each pixel at the specified 'indices' as a non-zero pixel in 'image'
void IndicesToBinaryImage(std::vector<itk::Index<2> > indices, UnsignedCharScalarImageType::Pointer image);

template <typename TImage>
void ITKImagetoVTKImage(typename TImage::Pointer image, vtkImageData* outputImage);

template <>
void ITKImagetoVTKImage<MaskImageType>(MaskImageType::Pointer image, vtkImageData* outputImage);

}

#include "Helpers.txx"

#endif