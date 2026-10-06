#include "Game.h"
void Game::Init(HWND hWnd)
{
	RendererInit(hWnd); // DirectXを初期化

	sound.Init();                   // サウンドを初期化
	sound.Play(SOUND_LABEL_BGM000); // BGMを再生

	m_player.Init("asset/chara_test.png", 3, 4); // プレイヤーを初期化（横3分割、縦4分割）
	m_player.SetPos(0.0f, 0.0f, 0.0f);      // 位置を設定
	m_player.SetSize(96.0f, 96.0f, 0.0f);   // 大きさを設定
	m_player.SetAngle(0.0f);                // 角度を設定
}

void Game::Update(void)
{
	input.Update(); // キー入力を更新

	// プレイヤーのアニメーション
	m_player.numU++;
	if (m_player.numU >= 3) {
		m_player.numU = 0;
	}

	// WASDでプレイヤーを移動
	DirectX::XMFLOAT3 pos = m_player.GetPos();
	if (input.GetKeyPress(VK_W)) { pos.y += 1.0f; }
	if (input.GetKeyPress(VK_A)) { pos.x -= 1.0f; }
	if (input.GetKeyPress(VK_S)) { pos.y -= 1.0f; }
	if (input.GetKeyPress(VK_D)) { pos.x += 1.0f; }
	m_player.SetPos(pos.x, pos.y, pos.z);

	// スペースキーでSEを再生
	if (input.GetKeyTrigger(VK_SPACE)) {
		sound.Play(SOUND_LABEL_SE000);
	}
}

void Game::Draw(void)
{
	RendererDrawStart(); // 描画開始

	m_player.Draw();      //プレイヤーを描画

	RendererDrawEnd();   // 描画終了
}

void Game::Uninit(void)
{
	m_player.Uninit(); // プレイヤーを終了

	sound.Uninit();    // サウンドを終了
	RendererUninit();  // DirectXを終了
}
