#include <gtest/gtest.h>
#include "oregonPlayer.h"
#include "qhsm.h"

TEST(OregonPlayerTest, GivePlayerABitOfRadiation) {
	OregonPlayer_ctor(27000, HEALTHY, 0);
	QMSM_INIT(the_oregonPlayer, (QEvt * )0);

	QEvt e;
	e.sig = RAD_RCVD_SIG;
	oregonPlayerQEvt Oregon_e;
	Oregon_e.super = e;
	Oregon_e.value = 1000;

	ASSERT_EQ(QMSM_DISPATCH(the_oregonPlayer, (QEvt * )&Oregon_e), Q_RET_HANDLED);
	ASSERT_EQ(GetCurrentState(), HEALTHY);

	OregonPlayer *me = reinterpret_cast<OregonPlayer *>(the_oregonPlayer);
	ASSERT_EQ(me->CharHP, 26000);
}
