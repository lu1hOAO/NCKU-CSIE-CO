// TODO :
	"addi t1,zero,16\n\t"
	"addi %[arith_cnt],%[arith_cnt],1\n\t"//cnt
	"LOOP:\n\t"
	"vsetvli t0,t1,e16,ta,ma\n\t"
	"vle16.v v0, (%0)\n\t"
	"sub t1,t1,t0\n\t"
	"slli t0,t0,1\n\t"
	"add %0,%0,t0\n\t"
	"vle16.v v1, (%1)\n\t"
	"add %1,%1,t0\n\t"
	"vadd.vv v2,v0,v1\n\t"
	"vse16.v v2,(%2)\n\t"
	"add %2,%2,t0\n\t"
	"addi %[arith_cnt],%[arith_cnt],6\n\t"//cnt
	"addi %[lw_cnt],%[lw_cnt],2\n\t"//cnt
	"addi %[sw_cnt],%[sw_cnt],1\n\t"//cnt
	"addi %[others_cnt],%[others_cnt],2\n\t"//cnt
	"bnez t1,LOOP\n\t"
