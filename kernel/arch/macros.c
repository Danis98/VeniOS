#include <arch/macros.h>

bool check_arch_macros(){
	bool valid_arch_flag=false;
	#ifdef __arch_x86
	valid_arch_flag=true;
	#endif
	return valid_arch_flag;
}
