#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include <utmp.h>

char *type_to_string();

main()
{
	struct utmp *uent;

	setutent();

	printf("%8s %*s   %10s  %10s   %5s %-20s  %s\n",
				 "Line",
				 sizeof(uent->ut_id),
				 "Id",
				 "Type",
				 "User",
				 "Pid",
				 "Host",
				 "Time");

	while (uent = getutent()) {
		printf("%8s %*s   %10s  %10s   %5d %-20s  %ld\n",
					 uent->ut_line,
					 sizeof(uent->ut_id),
					 uent->ut_id,
					 type_to_string(uent->ut_type),
					 uent->ut_user,
					 uent->ut_pid,
#ifdef NO_UT_HOST
		       "<unknown>",
#else /* !NO_UT_HOST */
					 uent->ut_host,
#endif /* !NO_UT_HOST */
					 uent->ut_time);
	}
	endutent();
}

char *type_to_string(int type)
{
	char *string;

	switch (type) {
	case INIT_PROCESS:
		string = "INIT";
		break;

	case LOGIN_PROCESS:
		string = "LOGIN";
		break;

	case USER_PROCESS:
		string = "USER";
		break;

	case DEAD_PROCESS:
		string = "DEAD";
		break;

	default:
		string = "UNKNWON";
		break;
	}

	return string;
}
