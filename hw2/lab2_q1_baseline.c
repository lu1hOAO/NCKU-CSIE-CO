// TODO : 
	"addi t1,zero,16\n\t"
	"addi %[arith_cnt],%[arith_cnt],1\n\t"//cnt
        "loop:\n\t"
        "lw t2,0(%[x])\n\t"
        "lw t3,0(%[h])\n\t"
        "add t4,t2,t3\n\t"
        "sw t4,0(%[y])\n\t"
        "addi %[x],%[x],2\n\t"
        "addi %[h],%[h],2\n\t"
        "addi %[y],%[y],2\n\t"
        "addi t1,t1,-1\n\t"
        "addi %[arith_cnt],%[arith_cnt],5\n\t"//cnt
        "addi %[lw_cnt],%[lw_cnt],2\n\t"//cnt
        "addi %[sw_cnt],%[sw_cnt],1\n\t"//cnt
        "addi %[others_cnt],%[others_cnt],1\n\t"//cnt
        "bnez t1,loop\n\t"
        
