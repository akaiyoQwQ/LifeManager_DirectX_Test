#pragma once
#include "Object.h"
#include "input.h"
#include "sound.h"

class Game {
private:
	Input input; //キー入力
	Sound sound; //サウンド

	Object m_player; //プレイヤーオブジェクト

public:
	void Init(HWND hWnd); // 初期化
	void Update();        // 更新
	void Draw();          // 描画
	void Uninit();        // 終了
};