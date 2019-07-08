#include "service.h"





const KeyStroke KeyStrokes[]= {
{    RAD_RCVD_SIG,                "RAD_RCVD",                  'r'    },
{    PILL_RESET_SIG,              "PILL_RESET",                '0'    },
{    PILL_GHOUL_SIG,              "PILL_GHOUL",                'g'    },
{    PILL_TEST_SIG,               "PILL_TEST",                 't'    },
{    PILL_REMOVED_SIG,            "PILL_REMOVED",              'q'    },
{    PILL_GHOUL_REMOVED_SIG,      "PILL_GHOUL_REMOVED",        '7'    },
{    TIME_TICK_1S_SIG,            "TIME_TICK_1S",              's'    },
{    TIME_TICK_10S_SIG,           "TIME_TICK_10S",             'd'    },
{    TIME_TICK_1M_SIG,            "TIME_TICK_1M",              'm'    },

{	PILL_ANY_SIG, 	              "PILL_ANY",                  'p'	},
{	PILL_HEAL_SIG, 	              "PILL_HEAL",	               '1'	},
{	PILL_RAD_X_SIG, 	          "PILL_RAD_X",	               '3'	},
{	PILL_BLESS_SIG, 	          "PILL_BLESS",	               '6'	},
{	PILL_CURSE_SIG, 	          "PILL_CURSE",	               '5'	},
{	PILL_ANTIRAD_SIG, 	          "PILL_ANTIRAD", 	           '4'	},
{	PILL_HEALSTATION_SIG, 	      "PILL_HEALSTATION",	       '2'	},

{    TERMINATE_SIG,               "TERMINATE",                 0x1B   }

};


unsigned int KeyNumber() {
	return sizeof(KeyStrokes)/sizeof(KeyStrokes[0]);
}
