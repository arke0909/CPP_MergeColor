#include "InfoUIManager.h"
InfoUIManager* InfoUIManager::instance = nullptr;

void InfoUIManager::RenderMergeInfoUI(int colorMixId)
{
	COLOR aColor = TransitionColor(colorInfo[colorMixId].first);
	COLOR bColor = TransitionColor(colorInfo[colorMixId].second);
	COLOR resultColor = TransitionColor(CalcBlockType(
		colorInfo[colorMixId].first, colorInfo[colorMixId].second));

	SetColor(aColor);
	cout << "�� ";
	SetColor();
	cout << "+ ";
	SetColor(bColor);
	cout << "�� ";
	SetColor();
	cout << "= ";
	SetColor(resultColor);
	cout << "��";
	SetColor();
}

void InfoUIManager::InputArrowInfoUI()
{
	cout << "�� : �·� �̵�\t�� : ��� �̵�\t�� : ���� �̵�\t�� : �Ʒ��� �̵�";
}
