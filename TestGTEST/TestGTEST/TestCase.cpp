#include "stdafx.h"
#include <gtest\gtest.h>

TEST(testGame, testGetNumberOfLivingCellsAround0)
{
	Game g0;
	g0.cellStatus[0][0] = 0;
	g0.cellStatus[0][1] = 1;
	g0.cellStatus[0][2] = 1;
	g0.cellStatus[1][0] = 1;
	g0.cellStatus[1][1] = 0;
	g0.cellStatus[1][2] = 0;
	g0.cellStatus[2][0] = 0;
	g0.cellStatus[2][1] = 0;
	g0.cellStatus[2][2] = 0;
	EXPECT_EQ(3, g0.GetNumberOfLivingCellsAround(0, 0));//EXPECT_EQ�ǱȽ�����ֵ�Ƿ����
}