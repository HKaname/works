#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <DirectXMath.h>
#include <memory>
#include "MeshBuffer.h"
#include "Shader.h"
#include "Texture.h"

class Sprite
{
public:
	static void Init();
	static void Uninit();
	static void Draw();
	static void MaskDraw();
	static void UIDraw();
	static void GoalEfectDraw();

	static void SetOffset(DirectX::XMFLOAT2 offset);
	static void SetSize(DirectX::XMFLOAT2 size);
	static void SetUVPos(DirectX::XMFLOAT2 pos);
	static void SetUVScale(DirectX::XMFLOAT2 scale);
	static void SetColor(DirectX::XMFLOAT4 color);
	static void SetTexture(Texture* tex);
	static void SetMaskTexture(Texture* Gtex, Texture* Btex);
	static void SetWorld(DirectX::XMFLOAT4X4 world);
	static void SetView(DirectX::XMFLOAT4X4 view);
	static void SetProjection(DirectX::XMFLOAT4X4 proj);
	static void SetRotateSpeed(float RottateSpeed);
	static void SetVertexShader(Shader* vs);
	static void SetPixelShader(Shader* ps);
	static void Settime(float time);
private:
	struct Data
	{
		std::shared_ptr<MeshBuffer> mesh;
		DirectX::XMFLOAT4X4 matrix[3];
		DirectX::XMFLOAT4 param[3];
		DirectX::XMFLOAT4 Gparam[3];
		DirectX::XMFLOAT4 Bparam[3];
		Texture* texture;
		Shader* vs;
		Shader* ps;
	};
	static Data m_data;
	static std::shared_ptr<VertexShader> m_defVS;
	static std::shared_ptr<PixelShader> m_defPS;
	static RenderTarget* m_UiRtv;
	static DepthStencil* m_UiDsv;
	static Texture* m_tex[2];
	static float m_RotateSpeed;
	static float m_Time;
};
#endif // __SPRITE_H__