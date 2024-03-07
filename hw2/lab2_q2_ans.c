// TODO : 
	"addi t0,zero,8\n\t"			//scalar 8
	"vsetvli t1,t0,e16,ta,ma\n\t"		//declare vector
	"vle16.v v1,(%0)\n\t"			//load p_x[j]
	"addi %[CPI4_cnt],%[CPI4_cnt],1\n\t"
	"addi %[CPI3_cnt],%[CPI3_cnt],2\n\t"
	"loop:\n\t"
	"lw t2, 0(%0)\n\t"              	//load p_x[i]	
	"vadd.vx v2,v1,t2\n\t"			//p_x[i]+p_x[j]	
	"vmseq.vx v3,v2,%[target]\n\t"	//v2==target
	"vse16.v v3,(%1)\n\t"			//store compare result in tmp2
	"lw t3,(%1)\n\t"		// store tmp2 in t3
	"bgt t3, zero,break\n\t"                 // find ans
	"addi %0,%0,2\n\t"			//next p_x[i]
	"addi t0,t0,-1\n\t"			//counter
	"addi %[CPI4_cnt],%[CPI4_cnt],3\n\t"
	"addi %[CPI3_cnt],%[CPI3_cnt],3\n\t"
	"addi %[CPI5_cnt],%[CPI5_cnt],2\n\t"
	"bnez t0,loop\n\t"
	"j false\n\t"
	"break:\n\t"
	"addi %[flag],zero,1\n\t"
	"addi %[CPI4_cnt],%[CPI4_cnt],1\n\t"
	"false:\n\t"
	

	
	
	
	
	
	



