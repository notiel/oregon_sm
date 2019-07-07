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

	auto r = QMSM_DISPATCH(the_oregonPlayer, (QEvt * )&Oregon_e);

	// Тут бы нам проверить, что состояние персонажа (r или the_oregonPlayer->current_)
	// то какое мы ожидаем. Но не вполне понятно как это сделать - состояние - это ссылка на функцию
	// внутри oregonPlayer.cpp. И в oregonPlayer.h эта функия не объявлена.
 	// Ну, проверим по крайней мере здоровье.
	OregonPlayer *me = reinterpret_cast<OregonPlayer *>(the_oregonPlayer);
	ASSERT_EQ(me->CharHP, 26000);
}
