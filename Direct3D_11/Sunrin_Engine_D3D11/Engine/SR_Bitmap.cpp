#include "SR_PCH.h"

#include "SR_Bitmap.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_Bitmap::SR_Bitmap() noexcept:
		m_bitmap{ nullptr }
	{

	}

	bool SR_Bitmap::CreateBitmap(const std::wstring & filePath)
	{
		std::wstring path{ L"Resources\\Textures\\" + filePath };

		Microsoft::WRL::ComPtr<IWICBitmapDecoder> WICBitmapDecoder{ nullptr };
		Microsoft::WRL::ComPtr<IWICBitmapFrameDecode> WICBitmapFrameDecode{ nullptr };
		Microsoft::WRL::ComPtr<IWICFormatConverter> WICFormatConverter{ nullptr };

		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetWICImagingFactory()->CreateDecoderFromFilename(path.c_str(), nullptr, GENERIC_READ, WICDecodeMetadataCacheOnDemand, WICBitmapDecoder.GetAddressOf()));
		SR_LOG_RF_HR_AUTO(WICBitmapDecoder->GetFrame(0, WICBitmapFrameDecode.GetAddressOf()));
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetWICImagingFactory()->CreateFormatConverter(WICFormatConverter.GetAddressOf()));
		SR_LOG_RF_HR_AUTO(WICFormatConverter->Initialize(WICBitmapFrameDecode.Get(), GUID_WICPixelFormat32bppPRGBA, WICBitmapDitherTypeNone, nullptr, 0.0f, WICBitmapPaletteTypeCustom));
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD2DDeviceContext()->CreateBitmapFromWicBitmap(WICFormatConverter.Get(), m_bitmap.GetAddressOf()));

		return true;
	}

}