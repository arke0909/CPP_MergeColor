#include "InfoUIManager.h"
InfoUIManager* InfoUIManager::instance = nullptr;

void InfoUIManager::RenderMergeInfoUI(int colorMixId)
{
	COLOR aColor = TransitionColor(colorInfo[colorMixId].first);
	COLOR bColor = TransitionColor(colorInfo[colorMixId].second);
	COLOR resultColor = TransitionColor(CalcBlockType(
		colorInfo[colorMixId].first, colorInfo[colorMixId].second));

	SetColor(aColor);
	cout << "■ ";
	SetColor();
	cout << "+ ";
	SetColor(bColor);
	cout << "■ ";
	SetColor();
	cout << "= ";
	SetColor(resultColor);
	cout << "■";
	SetColor();
}

void InfoUIManager::InputArrowInfoUI()
{
	cout << "← : 좌로 이동\t→ : 우로 이동\t↑ : 위로 이동\t↓ : 아래로 이동";
}
