#include<msk.h>


void choose_calc();
void print_calc();
void print_temp_calc();
void print_num_conv_calc();

/*       																									     */ void start();
void main()
{
	int gdriver=DETECT,gmode;

/*          																								     */ start();
	choose_calc();

	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

	circle(100,100,25);
	pf("hiii");
	getch();

	closegraph();

}

void choose_calc()
{
	int sel_calc;
	label:
	cls();
	pf("\n\t\t\t\033[1m      "TEXT_WHITE" C"TEXT_RED" A"TEXT_GREEN" L"TEXT_YELLOW" C"TEXT_BLUE" U"TEXT_MAGENTA" L"TEXT_CYAN" A"TEXT_WHITE" T"TEXT_RED" O"TEXT_GREEN" R   \n\t"RESET);

					   pf(RESET"                                "  BG_WHITE                      "||"RESET                          "                                   \n");
	pf("      \033[1;36m1\033[0m "); pf(BG_CYAN"                            "      RESET             "    \033[47m||\033[0m     \033[1;36m6\033[0m  "BG_BLUE"                            \n"     RESET"\t");
					 pf(BG_CYAN"  "RESET RESET TEXT_MAGENTA"    Normal Calculator   " BG_CYAN"  "RESET  "    \033[47m||\033[0m	  "                      BG_BLUE"  "RESET TEXT_MAGENTA"    Normal Calculator   "  BG_BLUE"  \n"RESET"\t");
					 pf(BG_CYAN"                            "      RESET             "    \033[47m||\033[0m	  "                      BG_BLUE"                            \n"     RESET"\t");
					   pf(RESET"                                "  BG_WHITE                      "||"RESET"                                   \n");

	pf("      \033[1;36m2\033[0m ");   pf(BG_RED"                            "     RESET             "    \033[47m||\033[0m     \033[1;36m7\033[0m  "BG_YELLOW"                            \n"   RESET"\t");
					   pf(BG_RED" "RESET TEXT_MAGENTA"     Binary Calculator   "BG_RED"  "RESET   "    \033[47m||\033[0m	  "                      BG_YELLOW" "RESET TEXT_MAGENTA"     Binary Calculator   "BG_YELLOW"  \n"RESET"\t");
					   pf(BG_RED"                            "     RESET             "    \033[47m||\033[0m  	  "              BG_YELLOW"                            \n"   RESET"\t");
					    pf(RESET"                                " BG_WHITE                      "||"RESET"                                   \n");

	pf("      \033[1;36m3\033[0m "); pf(BG_GREEN"                            "     RESET             "    \033[47m||\033[0m     \033[1;36m8\033[0m  "BG_GREEN"                            \n"     RESET"\t");
					 pf(BG_GREEN" "RESET TEXT_MAGENTA"  Temperature Calculator "BG_GREEN"  "RESET "    \033[47m||\033[0m	  "                      BG_GREEN" "RESET TEXT_MAGENTA"  Temperature Calculator "  BG_GREEN"  \n"RESET"\t");
					 pf(BG_GREEN"                            "     RESET             "    \033[47m||\033[0m  	  "              BG_GREEN"                            \n"     RESET"\t");
					    pf(RESET"                                " BG_WHITE                      "||"RESET"                                   \n");

	pf("      \033[1;36m4\033[0m ");pf(BG_YELLOW"                            "     RESET             "    \033[47m||\033[0m     \033[1;36m9\033[0m  "BG_RED"                            \n"       RESET"\t");
					pf(BG_YELLOW" "RESET TEXT_MAGENTA"      Area Calculator    "BG_YELLOW"  "RESET"    \033[47m||\033[0m	  "                      BG_RED" "RESET TEXT_MAGENTA"      Area Calculator    "    BG_RED"  \n"RESET"\t");
					pf(BG_YELLOW"                            "     RESET             "    \033[47m||\033[0m	  "                      BG_RED"                            \n"       RESET"\t");
					    pf(RESET"                                " BG_WHITE                      "||"RESET"                                   \n");

       pf("      \033[1;36m5\033[0m ");  pf(BG_BLUE"                            "      RESET             "    \033[47m||\033[0m    \033[1;36m10\033[0m  "BG_CYAN"                            \n"      RESET"\t");
					 pf(BG_BLUE" "RESET TEXT_MAGENTA"   Perimeter Calculator  " BG_BLUE"  "RESET  "    \033[47m||\033[0m	  "                      BG_CYAN" "RESET TEXT_MAGENTA"   Perimeter Calculator  "   BG_CYAN"  \n"RESET"\t");
					 pf(BG_BLUE"                            "      RESET             "    \033[47m||\033[0m	  "                      BG_CYAN"                            \n"      RESET"\t");
					   pf(RESET"                                "  BG_WHITE                      "||"RESET"                                   \n");



	pf("      Select a Calculator Type :-");
	sf("%d",&sel_calc);


	if(sel_calc<1||sel_calc>10)
	{
		pf(TEXT_RED"      \033[1;5;37mEnter a Valid value"RESET);
		delay(1500);
		goto label;
	}
	pf("\033[1;5;37m      Calc is Loading............."RESET);
	delay(2500);
}

void print_calc()
{

}

void print_temp_calc()
{

}

void print_num_conv_calc()
{

}


/*  																									     */ void start()
																										{



																										int dtime=100;
																										cls();
																										pf("\n\t\t          \033[1;31mCALCULATOR MADE BY \n\n\t\t              \033[32m   USING        \n\n\t\t \033[33m\t      C LANGUAGE");
																										delay(1000);
																										printf("\n\033[1;37m\t\t\t\t\t\t\t    --\033[34mversion \033[37m0\033[31m.\033[37m0a\033[0m\n\n");
																										pf("\033[0m\n\n\n\n");
																										pf("T"); delay(dtime);
																										pf("h"); delay(dtime);
																										pf("i"); delay(dtime);
																										pf("s "); delay(dtime);
																										pf("p"); delay(dtime);
																										pf("r"); delay(dtime);
																										pf("o"); delay(dtime);
																										pf("j"); delay(dtime);
																										pf("e"); delay(dtime);
																										pf("c"); delay(dtime);
																										pf("t "); delay(dtime);
																										pf("i"); delay(dtime);
																										pf("s "); delay(dtime);
																										pf("m"); delay(dtime);
																										pf("a"); delay(dtime);
																										pf("d"); delay(dtime);
																										pf("e "); delay(dtime);
																										pf("b"); delay(dtime);
																										pf("y "); delay(dtime);

																										//CME-A Boys in Green color
																										pf(TEXT_GREEN "C"); delay(dtime);
																										pf(TEXT_GREEN "M"); delay(dtime);
																										pf(TEXT_GREEN "E"); delay(dtime);
																										pf(TEXT_GREEN "-"); delay(dtime);
																										pf(TEXT_GREEN "A "); delay(dtime);
																										pf(TEXT_GREEN "B"); delay(dtime);
																										pf(TEXT_GREEN "o"); delay(dtime);
																										pf(TEXT_GREEN "y"); delay(dtime);
																										pf(TEXT_GREEN "s "); delay(dtime);

																										//Reset color and continue
																										pf(RESET "o"); delay(dtime);
																										pf("f "); delay(dtime);

																										//Aditya Polytechnic Colleges in Red color
																										pf(TEXT_RED "A"); delay(dtime);
																										pf(TEXT_RED "d"); delay(dtime);
																										pf(TEXT_RED "i"); delay(dtime);
																										pf(TEXT_RED "t"); delay(dtime);
																										pf(TEXT_RED "y"); delay(dtime);
																										pf(TEXT_RED "a "); delay(dtime);
																										pf(TEXT_RED "P"); delay(dtime);
																										pf(TEXT_RED "o"); delay(dtime);
																										pf(TEXT_RED "l"); delay(dtime);
																										pf(TEXT_RED "y"); delay(dtime);
																										pf(TEXT_RED "t"); delay(dtime);
																										pf(TEXT_RED "e"); delay(dtime);
																										pf(TEXT_RED "c"); delay(dtime);
																										pf(TEXT_RED "h"); delay(dtime);
																										pf(TEXT_RED "n"); delay(dtime);
																										pf(TEXT_RED "i"); delay(dtime);
																										pf(TEXT_RED "c "); delay(dtime);
																										pf(TEXT_RED "C"); delay(dtime);
																										pf(TEXT_RED "o"); delay(dtime);
																										pf(TEXT_RED "l"); delay(dtime);
																										pf(TEXT_RED "l"); delay(dtime);
																										pf(TEXT_RED "e"); delay(dtime);
																										pf(TEXT_RED "g"); delay(dtime);
																										pf(TEXT_RED "e "); delay(dtime);
																										pf("\033[1;36m(\033[0m533437\033[1;36m)"RESET);


																										pf("\033[1;37m\n\n\t\t\tTeam Member Pin Numbers:\n");
																										delay(500);
																										pf("\033[1;35m\t\t\t   1\033[1;37m.\033[1;36m 23255\033[1;37m-\033[1;36mCM\033[1;37m-\033[1;36m003\n");
																										delay(500);
																										pf("\033[1;35m\t\t\t   2\033[1;37m.\033[1;36m 23255\033[1;37m-\033[1;36mCM\033[1;37m-\033[1;36m023\n");
																										delay(500);
																										pf("\033[1;35m\t\t\t   3\033[1;37m.\033[1;36m 23255\033[1;37m-\033[1;36mCM\033[1;37m-\033[1;36m024\n");
																										delay(500);
																										pf("\033[1;35m\t\t\t   4\033[1;37m.\033[1;36m 23255\033[1;37m-\033[1;36mCM\033[1;37m-\033[1;36m031\n");
																										delay(500);
																										pf("\n\t\t     ");
																										printf(TEXT_BLACK" \033[5mEnter any key to continue" RESET);
																										getch();
																										cls();


/*  																								     	     */ }

