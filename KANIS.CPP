
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<process.h>
void main()
{
	float floattest[2][2];
	int name=65;
        int confportalorbuildstr,tempconf=0;  /*To confirm whether structure is building type or frame type*/ 
	float baylengthplanexy[5],storeylength[5];
	float commoniforcolumn,commoniforbeam,storeywisesamei[5],storeywisesameiforcolumn[5],verticalcolumnssamei[5];
	float beamlengthplanexy[5][5][5],beamlengthplanezy[5][5][5],columnlength[5][5][5],ivaluebeamplanexy[5][5][5],ivaluebeamplanezy[5][5][5];
	float ivalcolplanezy[5][5][5],ivalcolplanexy[5][5][5];
      /*declaration for load entry on beams starts*/
	 /*declaration of UDL if all beams carry UDL*/  
	int loadtypeplanexy[5][5][5],loadtypeplanezy[5][5][5];
	float loadvalplanexy[5][5][5],loadvalplanezy[5][5][5];
	float distforpointloadplanexy[5][5][5],distforpointloadplanezy[5][5][5];
	float fixemplanexy[5],fixemplanezy[5];
	float commonudlforbeamsplanexy=0,storeywisesameudl[5][5];
	int confallbeamudltake=0;
        int confsametypeudlforbeam=0;
         /*declaration of POINT loads*/
	int numofpointloads[8][8][8],confextraudl[8][8][8];
	float pointloadvalue[2][4][4][4],pointloaddistance[2][4][4][4]; 
      /*declaration for load entry on beams ends*/
    /*Execution part starts */
      /*Fixed end moments*/
	float fixendmomduetopointloadtoleftjoint[2][4][4][4],fixendmomduetoudltoleftpointforallbeamudl[2][8][8];
	float fixendmomduetopointloadtorightjoint[2][4][4][4],fixendmomduetoudltorightpointforallbeamu[2][8][8];
	float finalfixendmomtoleftside[2][5][5],finalfixendmomtorightside[2][5][5];
      /*Finding k val,sigma k & rotation factor*/
	float kvaluetobeams[2][5][5],kvaluetocolumns[2][5][5];
	float sigmakval[2][5][5];
	float rfvaluetobeamstoleftofjoint[2][5][5],rfvaluetobeamstorightofjoint[2][5][5];
	float rfvaluetobeamstotopofjoint[2][5][5],rfvaluetobeamstobottomofjoint[2][5][5];
      /*Joint Fix End Moments*/
	float jointfixendmom[2][8][8];
      /*Finding M.dash moments*/
	float mdashmomforbeamtoleftside[2][8][8],mdashmomforbeamtorightside[2][8][8];
	float mdashmomforcolumntowardstop[2][8][8],mdashmomforcolumntowardsbottom[2][8][8];
      /*Finding Final End Moments*/
	float finalendmomtoleftsideofbeam[2][8][8],finalendmomtorightsideofbeam[2][8][8];
	float finalendmomtotopsideofcolumn[2][8][8],finalendmomtobottomsideofcolumn[2][8][8];
      /*For graphics*/
	float x,y,storeyscale,bayscale,baylengthchange[10],lerftohlengthchange=0,rightohlengthchange=0;
	float totalbaylength,totalstoreylength=0,scale,totalstoreylengthchange;
	float graphaddforstorey=0,graphaddforbay;
	int i,storey,bays;
	int ax,ay,driver=DETECT,mode;
	float storeylengthchange[20],baylength[20]; /*storeylength[i]*/
	int j,k,baysinplanexy,baysinplanezy,storeys=0;
	int confsametypeiforcol,confsametypeiforbeam;
	int incasecontbeam=0;
      /*Confirming overhanging*/
	int overhangtype=4,conffixleft=1,conffixright=1,confleftoh=0,confrightoh=0;
	float rightohlength=0,leftohlength=0,rightohpointloadval=0,leftohpointloadval=0;
	float overhangmomtoright=0,overhangmomtoleft=0;       /* Moments due to overhanging members */
      /*For Vertical members in Frame structures*/
	int confvertmembers=0,vertpresencetojoint[5],numofvertmem=0,confmemtopresentjoint[5],duplicate_cmp[5],ptloadonvertmember[1][1][7],tempi=0;
	int key=1,mn,kl;
	float vertmemloadval[1][1][7][3],horloaddist[1][1][7][3],vertfixendmomtotop[1][1][6],tempo=0;
      /* Settlement data values*/
	int confsettlement=0,numofse=0,confsettlepresence[7];
	float eival=0,setlmmval[7],delta=0,diff=0;	

	clrscr();
     /*initializing values*/
      for(i=0;i<1;i++)
	{
	     for(j=0;j<8;j++)
	     {
		for(k=0;k<8;k++)
		{
		      beamlengthplanexy[i][j][k]=0;
		      beamlengthplanezy[i][j][k]=0;
		      ivaluebeamplanexy[i][j][k]=0;
		      ivaluebeamplanezy[i][j][k]=0;
		      ivalcolplanezy[i][j][k]=0;
		      ivalcolplanexy[i][j][k]=0;
		      columnlength[i][j][k]=0;
		      loadvalplanexy[0][j][k]=0;
		      loadtypeplanexy[0][j][k]=1;
		      beamlengthplanexy[0][j][k]=0;
		      fixendmomduetoudltoleftpointforallbeamudl[0][j][k]=0;
		      fixendmomduetoudltorightpointforallbeamu[0][j][k]=0;
		      finalfixendmomtoleftside[0][j][k]=0;
		      finalfixendmomtorightside[0][j][k]=0;
		      kvaluetobeams[0][j][k]=0;
		      kvaluetocolumns[0][j][k]=0;
		      sigmakval[0][j][k];
		      mdashmomforbeamtoleftside[0][j][k]=0;
		      mdashmomforbeamtorightside[0][j][k]=0;
		      mdashmomforcolumntowardstop[0][j][k]=0;
		      mdashmomforcolumntowardsbottom[0][j][k]=0;
		      finalendmomtoleftsideofbeam[0][j][k]=0;
		      finalendmomtorightsideofbeam[0][j][k]=0;
		      finalendmomtotopsideofcolumn[0][j][k]=0;
		      finalendmomtobottomsideofcolumn[0][j][k]=0;
		      horloaddist[0][0][j][k]=0;
			}
	     }
	}
	for(i=0;i<7;i++)
	{
	   confmemtopresentjoint[i]=0;
	   ptloadonvertmember[0][1][i]=0;
	  vertfixendmomtotop[0][1][i]=0;
	  confsettlepresence[i]=0;  
	  setlmmval[i]=0;
	}
	/*printf("Test for float\n");
	scanf("%f",&floattest[2][2]);*/
	printf("Enter structure type\n");
	printf("1. Building type\n");
	printf("2. Frame structure\n");
	scanf("%d",&confportalorbuildstr);
	if(confportalorbuildstr==2)
	{
	    tempconf=1;
	    incasecontbeam=10;
	    printf("  Input for Overhanging \n");
	    printf("1.Overhanging To Right \n2.Overhanging To Left\n3.Both side Overhanging\n4.Both side fix\n");
	    scanf("%d",&overhangtype);
	    if(overhangtype==1)
	    {
		 conffixright=0;
		 confrightoh=1;
	    }
	    if(overhangtype==2)
	    {
		 conffixleft=0;
		 confleftoh=1;
	    }
	    if(overhangtype==3)
	    {
		 conffixright=0;
		 conffixleft=0;
		 confleftoh=1;
		 confrightoh=1;
	    }

 	}
	printf("Enter no. of bays in xy plane\n");
	scanf("%d",&baysinplanexy);
	if(confportalorbuildstr!=2)
	{
	  printf("Enter no. of storeys\n");
	  scanf("%d",&storeys);
	  for(j=1;j<storeys+1;j++)
	  {
		printf("Enter length for storey %d \n",j);
		scanf("%f",&storeylength[j]);
		for(k=1;k<baysinplanexy+2;k++)
		{

			 columnlength[0][j][k]=storeylength[j];
		}
	  }
	}
	for(j=1;j<baysinplanexy+1;j++)
	{
	       printf("Enter length of bay %d\n",j);
	       scanf("%f",&baylengthplanexy[j]);
	       for(k=1;k<storeys+1+tempconf;k++)
	       {
		   beamlengthplanexy[0][k][j]=baylengthplanexy[j];
	       }
	}
  /*Entering I value for BEAMS*/
	printf("\n 1.Value of I for all beams is same\n 2.Value of I is same only to storeys\n 3.Value of I are different\n");
	scanf("%d",&confsametypeiforbeam);
	if(confsametypeiforbeam==1)
	{   
	  printf("Enter common I value for beams\n");
	  scanf("%f",&commoniforbeam);
	  for(j=1;j<storeys+1+tempconf;j++)
	  {
		for(k=1;k<baysinplanexy+1;k++)
		{
		     
			ivaluebeamplanexy[0][j][k]=commoniforbeam;
		}
	  }
	  goto skipresti;	
	}
	if(confsametypeiforbeam==2)
	{
	     
	  for(j=1;j<storeys+1+tempconf;j++)
	  {
		printf("Enter I Value for storey %d\n",j);
		scanf("%f",&storeywisesamei[j]);
		for(k=1;k<baysinplanexy+1;k++)
		{
			ivaluebeamplanexy[0][j][k]=storeywisesamei[j];
		}
          }
	  goto entrybeamivalueover;
 	}
	if(confsametypeiforbeam==3)
	{
	    for(j=1;j<storeys+1+tempconf;j++)
	    {
		for(k=1;k<baysinplanexy+1;k++)
	  	{
		    printf("Enter I value for mem %d in storey %d \n",k,j);
		    scanf("%f",&ivaluebeamplanexy[0][j][k]);
		}
	    }
	    goto entrybeamivalueover;
	}
	{
	   skipresti:
	   goto entrybeamivalueover;

	}
	entrybeamivalueover:
  /*Entering I value for COLUMNS*/
	if(confportalorbuildstr==1)
	{	
	printf("\n 1.Value of I is same for all columns\n 2.Value of I is same storey wise \n 3.Value of I is same vertically \n 4.Value of I are different\n");
	scanf("%d",&confsametypeiforcol);
	if(confsametypeiforcol==4)
	{
	    for(j=1;j<storeys+1+tempconf;j++)
	    {
		
		for(k=1;k<baysinplanexy+2;k++)
		{
			 printf("Enter I value for column %d in storey %d \n",k,j);
			 scanf("%f",&ivalcolplanezy[0][j][k]);						 
		}
            }
	     goto entrycolumnivalueover;
	}
	if(confsametypeiforcol==2)
	{
	    for(j=1;j<storeys+1;j++)
	    {
		printf("Enter I value for columns of storey %d",j);
		scanf("%f",&storeywisesameiforcolumn[j]);
		for(k=1;k<baysinplanexy+2;k++)
		{
		       ivalcolplanezy[0][j][k]=storeywisesameiforcolumn[j];
		}      	
	    }
	    goto entrycolumnivalueover;
	}
	if(confsametypeiforcol==3)
	{
	    for(j=1;j<baysinplanexy+2;j++)
	    {
		printf("Enter I value for vertical columns %d\n",j);
		scanf("%f",&verticalcolumnssamei[j]);
		for(k=1;k<storeys+1;k++)
		{
		    ivalcolplanezy[0][k][j]=verticalcolumnssamei[j];
		}
	    }
	    goto entrycolumnivalueover;
	}
	if(confsametypeiforcol==1)
	{
	    printf("Enter common I for all for columns\n");
	    scanf("%f",&commoniforcolumn);
	    for(j=1;j<storeys+1;j++)
	    {
		for(k=1;k<baysinplanexy+2;k++)
		{
		    ivalcolplanezy[0][j][k]=commoniforcolumn;
		}
	    }
	    goto entrycolumnivalueover;
	}  
	
	entrycolumnivalueover:
        }                         /* If confportalorbuildstr==1 over */
      /*printing data entered*/
        printf("TEST\n");
	printf("Length of beams are\n");
	for(j=1;j<storeys+1+tempconf;j++)
	{
		for(k=1;k<baysinplanexy+1;k++)
		{
		     printf("   %f   ",beamlengthplanexy[0][j][k]);

		}
		printf("\n\n\n");
	}
	printf("I value for beams are\n");
	for(j=1;j<storeys+1+tempconf;j++)
	{
		for(k=1;k<baysinplanexy+1;k++)
		{
		    printf("  %f  ",ivaluebeamplanexy[0][j][k]);

		}
		printf("\n\n\n");
	}
     
	printf("Length of columns are\n");
	for(j=1;j<storeys+1+tempconf;j++)
	{

		for(k=1;k<baysinplanexy+2;k++)
		{

			 printf("  %f  ",columnlength[0][j][k]);

		}
		printf("\n\n\n");
	}
	 printf("I value for columns are\n");
	 for(j=1;j<storeys+1+tempconf;j++)
	{

		for(k=1;k<baysinplanexy+2;k++)
		{
			 printf("  %f  ",ivalcolplanezy[0][j][k]);
		}
		printf("\n\n\n");
	}
     
   /*finding fixed end moments*/
        printf("Do all beams carry UDL?\n");   /*all beam UDL/*
	
/*-12*/	{
	    scanf("%d",&confallbeamudltake);
	    if(confallbeamudltake==1)
	    {
	    getch();
	    clrscr();
	    printf("Take it\n");
	    for(j=1;j<storeys+1+tempconf;j++)
	    {
		for(k=1;k<baysinplanexy+1;k++)
		{
		   
		      loadtypeplanexy[0][j][k]=0;

		}
	     }
	    printf("\n 1.Value of UDL is same throughout\n 2.Value of UDL is same for storeys only  (Ignore if struct. is continous beam)\n 3.UDL for members are different\n");
	    scanf("%d",&confsametypeudlforbeam);
   /*-1*/   {
	       if(confsametypeudlforbeam==1)
	       {
		  printf("Enter Common UDL for beams\n");
		  scanf("%f",&commonudlforbeamsplanexy);
		  for(j=1;j<storeys+1+tempconf;j++)
		  {
		     for(k=1;k<baysinplanexy+1;k++)
		     {

		      loadvalplanexy[0][j][k]=commonudlforbeamsplanexy;
		       printf("  %f  ",commonudlforbeamsplanexy);
		     }
		     printf("\n\n");
		  }
		goto udlover;
	       }

	      else if(confsametypeudlforbeam==2)
	      {
		 for(j=1;j<storeys+1+tempconf;j++)
		 {
		     printf("Enter UDL for storey %d \n",j);
		     scanf("%f",&storeywisesameudl[0][j]);
		 }


		for(j=1;j<storeys+1+tempconf;j++)
		{
		    for(k=1;k<baysinplanexy+1;k++)
		    {

		      loadvalplanexy[0][j][k]=storeywisesameudl[0][j];
		      printf("  %f  ",loadvalplanexy[0][j][k]);
		    }
		    printf("\n\n\n");
		}
		goto udlover;
	     }

	     if(confsametypeudlforbeam==3);
	     {
		for(j=1;j<storeys+1+tempconf;j++)
		{
		   printf("Now u r printing UDL for beams of storey %d\n",j);
		   for(k=1;k<baysinplanexy+1;k++)
		   {
			 scanf("%f",&loadvalplanexy[0][j][k]);

		   }
		   printf("\n");
		}
		printf("UDL u entered are as follows\n");
		for(j=1;j<storeys+1+tempconf;j++)
		{
		    for(k=1;k<baysinplanexy+1;k++)
		    {
			printf("  %f  ",loadvalplanexy[0][j][k]);
		    }
		    printf("\n\n\n");
		}
		goto udlover;
	     }
	   udlover:
	  }  /*-1*/
	 }
      }/*-12confallbeamudl*/          /*all beam UDL*/
   
      for(j=1;j<storeys+1+tempconf;j++)
      {
	   for(k=1;k<baysinplanexy+1;k++)
	   {
		getch();
		clrscr(); 
		printf("Enter no. of POINT loads on member %d of storey %d\n",k,j);
		scanf("%d",&numofpointloads[0][j][k]);
		for(i=1;i<numofpointloads[0][j][k]+1;i++)
		{
		      printf("\n Enter value for LOAD no. %d \n\n",i);
		      scanf("%f",&pointloadvalue[0][j][k][i]);
		      printf("\nEnter distance between left joint to load\n");
		      scanf("%f",&pointloaddistance[0][j][k][i]);
		}
		if(confallbeamudltake!=1)
		{
		      printf("IS there any UDL?\n");
		      scanf("%d",&confextraudl[0][j][k]);
		      if(confextraudl[0][j][k]==1)
		      {
			loadtypeplanexy[0][j][k]=0;
		        printf("Enter Value of UDL\n");
		        scanf("%f",&loadvalplanexy[0][j][k]);
		      }
		}
	   }
      }
     /* Entering Loads for Overhanging Members */
/*oh*/ {                       /* For all Overhang types written in sequence */
	if((overhangtype==1)||(overhangtype==3))
	{
	   printf("Enter overhanging Length (Right side) ...    (If no Overhanging - Press 0)\n");
       	   scanf("%f",&rightohlength);
	   if(rightohlength!=0)
	   {
		printf("Enter point load value \n");
		scanf("%f",&rightohpointloadval);
		overhangmomtoright=-(rightohpointloadval*rightohlength);
		printf("Overhanging moment = %f \n",overhangmomtoright);
	   }
	}
	if((overhangtype==2)||(overhangtype==3))
	{
	   printf("Enter overhanging Length (Left side) ...    (If no Overhanging - Press 0)\n");
       	   scanf("%f",&leftohlength);
	   if(leftohlength!=0)
	   {
		printf("Enter point load value \n");
		scanf("%f",&leftohpointloadval);
		overhangmomtoleft=(leftohpointloadval*leftohlength);
		printf("Overhanging moment = %f \n",overhangmomtoleft);
	   }
	}	   	   	
       }  /*oh*/
     /* Vertical Members in Frame structures & settlement*/
/*Vf*/ {
	 if(confportalorbuildstr==2)
	 {
	   printf("Are there any vertical members? (if no press '0')\n");
	   scanf("%d",&confvertmembers);
	   if(confvertmembers==1)
	   {
	      printf("Enter presence of vert. mem to joints using '1' & '0'\n\n");
	      for(i=1;i<baysinplanexy+2;i++)
	      {
		printf(" j%d ",i);
	      }
	      printf("\n\n");
	      j=1;
	      for(i=1;i<baysinplanexy+2;i++)
	      {
		scanf("%d",&vertpresencetojoint[i]);
		if(vertpresencetojoint[i]==1)
		{
                  
		  confmemtopresentjoint[j]=i;
		  numofvertmem=numofvertmem+1;
		  j=j+1;
		}
	      }
	      j=0;

	      /* for(i=1;i<numofvertmem+1;i++)              
	      {
		 duplicate_cmp[i]=confmemtopresentjoint[i];
	      }	
	      if(confmemtopresentjoint[1]==1)           This shifting in values has been done in order to print graphics properly horizontal members in portal frames
	      {
		 key=2;
		 for(i=1;i<numofvertmem+1;i++)
		 {
		   duplicate_cmp[i]=duplicate_cmp[i+1];
	         }	
	      }       */

	      printf("Num of Vertical members are %d\n",numofvertmem);
	      printf("Enter property\n\n");
	      printf("        ");
	      for(i=1;i<numofvertmem+1;i++)              
	      {
		  printf(" j%d ",confmemtopresentjoint[i]);
	      }	 
	      printf("\n");     
	      printf("Length   ");
	      for(i=1;i<numofvertmem+1;i++)              /* Entering Length */
	      {
		  scanf("%f",&columnlength[0][1][confmemtopresentjoint[i]]);
	      }
	      printf("\n");
	      printf("I Val   "); 
	      for(i=1;i<numofvertmem+1;i++)              /* Entering I Value */
	      {
		  scanf("%f",&ivalcolplanezy[0][1][confmemtopresentjoint[i]]);
	      }

	      printf("\n");
	      printf("Loads   "); 
	      for(i=1;i<numofvertmem+1;i++)              /* Entering no. of LOADS */
	      {
		  scanf("%d",&ptloadonvertmember[0][1][confmemtopresentjoint[i]]);
	      }

	      printf("\n\n VERTICAL members\n\n");    /* del */
	      for(i=1;i<numofvertmem+1;i++)
	      {
                   printf("PROPERTY   j%d    %f    %f     %d\n",confmemtopresentjoint[i],columnlength[0][1][confmemtopresentjoint[i]],ivalcolplanezy[0][1][confmemtopresentjoint[i]],ptloadonvertmember[0][1][confmemtopresentjoint[i]]);
	      }
	      printf("ptloadonvertmember[0][1][confmemtopresentjoint[2]] is %d \n",ptloadonvertmember[0][1][confmemtopresentjoint[2]]);
	      for(i=1;i<numofvertmem+1;i++)              /* Entering no. of LOADS */
	      {
		 printf("\n For Joint %d \n",confmemtopresentjoint[i]);
		 tempi=(ptloadonvertmember[0][1][confmemtopresentjoint[i]]);
		 printf("Value of Tempi = %d \n",tempi);
		 for(j=1;j<(tempi+1);j++)
		 {
                       printf("Enter Load %d Val \n",j);
		       scanf("%f",&vertmemloadval[0][0][i][j]);
		       printf("Dist From Joint \n");	
		       scanf("%f",&horloaddist[0][0][i][j]);
		       printf("tempo val is %f Beginning\n",tempo);
		       tempo=tempo+(-((vertmemloadval[0][0][i][j])*(horloaddist[0][0][i][j])*(columnlength[0][1][confmemtopresentjoint[i]]-horloaddist[0][0][i][j])*(columnlength[0][1][confmemtopresentjoint[i]]-horloaddist[0][0][i][j]))/((columnlength[0][1][confmemtopresentjoint[i]])*(columnlength[0][1][confmemtopresentjoint[i]])));
		       printf("tempo val is %f \n",tempo);

		 }
		 vertfixendmomtotop[0][1][i]=tempo;
		 tempo=0;
		 printf("Your Fix End Mom = %f \n\n",vertfixendmomtotop[0][1][i]);		       
	      }
	/* Temp printer */                   /* del */
	      printf("\n\n");
	      tempi=0;
	      for(i=1;i<numofvertmem+1;i++)              
	      {
		 printf("\n For Joint %d \n",confmemtopresentjoint[i]);
		 tempi=(ptloadonvertmember[0][1][confmemtopresentjoint[i]]);
		 printf("Value of Tempi = %d \n",tempi);
		 for(j=1;j<(tempi+1);j++)
		 {
                       printf("Load %d Val Entered \n",j);
		       printf(" Load val is %f\n",vertmemloadval[0][0][i][j]);
		       printf("Dist is %f\n",horloaddist[0][0][i][j]);
		       getch();
		 }	       
	      }
		getch();
	   }
        /* Confirm Settlement */

   /*se*/ printf("Is there any settlement?\n");     
	  scanf("%d",&confsettlement);
	  if(confsettlement==1)
	  {
	    printf("Enter Value of 'EI' (kn/sq.m)\n");
	    scanf("%f",&eival); 
	    printf("Enter no. of settlement supports\n");
	    scanf("%d",&numofse);
	    printf("Enter supports which undergo settlement\n\n");
	    for(int lg=1;lg<numofse+1;lg++)
	    {
		printf("JOINT   ");
   		scanf("%d",&confsettlepresence[lg]);
		printf("\nSETTLE VAL in mm   ");
		scanf("%f",&setlmmval[confsettlepresence[lg]]);
		printf("\n\n");
	    }
	  
	  }  /*se*/
	 }
	}  /*vf*/
	

		
	
 /* ------------------------------------------------------------------------------------------------------ */	  

  /*Execution starts*/
   /*Finding Fix End Moments*/
 /*-1*/ {
	  for(j=1;j<storeys+1+tempconf;j++)
	  {
	       for(k=1;k<baysinplanexy+1;k++)
	       {
		   for(i=1;i<numofpointloads[0][j][k]+1;i++)
		   {
			fixendmomduetopointloadtoleftjoint[0][j][k][i]=-(pointloadvalue[0][j][k][i]*pointloaddistance[0][j][k][i]*(beamlengthplanexy[0][j][k]-pointloaddistance[0][j][k][i])*(beamlengthplanexy[0][j][k]-pointloaddistance[0][j][k][i]))/(beamlengthplanexy[0][j][k]*beamlengthplanexy[0][j][k]);
			fixendmomduetopointloadtorightjoint[0][j][k][i]=(pointloadvalue[0][j][k][i]*(pointloaddistance[0][j][k][i])*(pointloaddistance[0][j][k][i])*(beamlengthplanexy[0][j][k]-pointloaddistance[0][j][k][i]))/(beamlengthplanexy[0][j][k]*beamlengthplanexy[0][j][k]);
		   }
	       }
	  }
	  printf("TEst 1");      /*del all these test values after completion*/
	  {
		for(j=1;j<storeys+1+tempconf;j++)
		{
		    for(k=1;k<baysinplanexy+1;k++)
		    {
			fixendmomduetoudltoleftpointforallbeamudl[0][j][k]=-((loadvalplanexy[0][j][k])*(beamlengthplanexy[0][j][k]*beamlengthplanexy[0][j][k]))/12;
			fixendmomduetoudltorightpointforallbeamudl[0][j][k]=((loadvalplanexy[0][j][k])*(beamlengthplanexy[0][j][k]*beamlengthplanexy[0][j][k]))/12;
		    }
		}
	   }
	printf("TEst 2");
	for(j=1;j<storeys+1+tempconf;j++)
	{
	       for(k=1;k<baysinplanexy+1;k++)
	       {
		    for(i=1;i<numofpointloads[0][j][k]+1;i++)
		    {
		        finalfixendmomtoleftside[0][j][k]=finalfixendmomtoleftside[0][j][k]+fixendmomduetopointloadtoleftjoint[0][j][k][i];
			finalfixendmomtorightside[0][j][k]=finalfixendmomtorightside[0][j][k]+fixendmomduetopointloadtorightjoint[0][j][k][i];
		    }
		}
	}
	printf("TEst 3");
	for(j=1;j<storeys+1+tempconf;j++)
	{
	       for(k=1;k<baysinplanexy+1+tempconf;k++)
	       {
		        finalfixendmomtoleftside[0][j][k]=finalfixendmomtoleftside[0][j][k]+fixendmomduetoudltoleftpointforallbeamudl[0][j][k];
			finalfixendmomtorightside[0][j][k]=finalfixendmomtorightside[0][j][k]+fixendmomduetoudltorightpointforallbeamudl[0][j][k];
	       }
	}
	if(((overhangtype==1)||(overhangtype==3))&&(rightohlength!=0))
	{
		finalfixendmomtoleftside[0][1][baysinplanexy+1]=overhangmomtoright;
	}
	if(((overhangtype==2)||(overhangtype==3))&&(leftohlength!=0))
	{
		finalfixendmomtorightside[0][1][0]=overhangmomtoleft;
	}
       // fix end mom changed due to settlement
        if(confsettlement==1)
	{
	   for(int lg=1;lg<baysinplanexy+1;lg++)
	   { 
	      delta=(setlmmval[lg]-(setlmmval[lg+1]))/1000;  /* div by 100 to convert to std. */
	      diff=(6*eival*delta)/(beamlengthplanexy[0][1][lg]*beamlengthplanexy[0][1][lg]);
	      finalfixendmomtoleftside[0][1][lg]=finalfixendmomtoleftside[0][1][lg]+diff;
	      finalfixendmomtorightside[0][1][lg]=finalfixendmomtorightside[0][1][lg]+diff;
	      //printf("\ncentre fix end mom \n");     /*del*/
	      printf("\n At joint %d\n",lg);
	      printf("CHANGED FEM = Left %f  ,  Right %f \n\n",finalfixendmomtoleftside[0][1][lg],finalfixendmomtorightside[0][1][lg]);
	      printf("Delta=%f  Diff=%f \n",delta,diff);
	      //printf("Beam length=%f\n",beamlengthplanexy[0][1][lg]);
	      getch();
	   }
	}

     	printf("TEst 4");
        printf(" First beam I val is %f",beamlengthplanexy[0][1][1]);
     /*Finding k val,sigma k & rotation factor*/
	for(j=1;j<storeys+1+tempconf;j++)
	{
	       for(k=1;k<baysinplanexy+1;k++)
	       {
			kvaluetobeams[0][j][k]=ivaluebeamplanexy[0][j][k]/beamlengthplanexy[0][j][k];
	       }
	}
	if((confportalorbuildstr==2)&&(confrightoh==1))
	{
	     kvaluetobeams[0][1][baysinplanexy]=(0.75)*kvaluetobeams[0][1][baysinplanexy];
	}
	if((confportalorbuildstr==2)&&(confleftoh==1))
	{
	     kvaluetobeams[0][1][1]=(0.75)*kvaluetobeams[0][1][1];
	}	
     	printf("\nTEst 5");
	if(confportalorbuildstr==1)
	{
	   for(j=1;j<storeys+1+tempconf;j++)
	   {

		for(k=1;k<baysinplanexy+2;k++)
		{			       
			kvaluetocolumns[0][j][k]=ivalcolplanezy[0][j][k]/columnlength[0][j][k];
		}
	   } 
	} 
	for(i=1;i<6;i++)        /* del */
	{
	   printf(" I %f",ivalcolplanezy[0][1][i]);
	   printf(" L %f\n",columnlength[0][1][i]);
	}
	if((confportalorbuildstr==2)&&(confvertmembers==1))
	{
	   for(i=1;i<baysinplanexy+2;i++)
	   {
              if(vertpresencetojoint[i]==1)
	      {
		printf("\n\n ival %f & collen %f \n\n",ivalcolplanezy[0][1][i],columnlength[0][1][i]);
		kvaluetocolumns[0][1][i]=ivalcolplanezy[0][1][i]/columnlength[0][1][i];
	        printf("\nK val to col %d is %f \n",i,kvaluetocolumns[0][1][i]);
	      }
	   }
	}

     	printf("TEst 6");
	{			/*Finding Sigma k value*/
	    for(j=1;j<storeys+1+tempconf;j++)
	    {
		for(k=1;k<baysinplanexy+2;k++)
		{
		     sigmakval[0][j][k]=kvaluetobeams[0][j][k]+kvaluetobeams[0][j][k-1]+kvaluetocolumns[0][j][k]+kvaluetocolumns[0][j-1][k];
		}
	    }
	}
     	printf("TEst 7");
	    for(j=1;j<storeys+1+tempconf;j++)
	    {
		for(k=1;k<baysinplanexy+2;k++)
		{
		     rfvaluetobeamstoleftofjoint[0][j][k]=-((0.5)*(kvaluetobeams[0][j][k-1])/sigmakval[0][j][k]);
		     rfvaluetobeamstorightofjoint[0][j][k]=-((0.5)*(kvaluetobeams[0][j][k])/sigmakval[0][j][k]);
		     rfvaluetobeamstotopofjoint[0][j][k]=-((0.5)*(kvaluetocolumns[0][j-1][k])/sigmakval[0][j][k]);
		     rfvaluetobeamstobottomofjoint[0][j][k]=-((0.5)*(kvaluetocolumns[0][j][k])/sigmakval[0][j][k]);
		}
	    }
     	printf("TEst 8");
	    for(j=1;j<storeys+1+tempconf;j++)
	    {
		for(k=1;k<baysinplanexy+2;k++)
		{
		     jointfixendmom[0][j][k]=finalfixendmomtoleftside[0][j][k]+finalfixendmomtorightside[0][j][k-1];
		}
	    }

	    for(i=1;i<numofvertmem+1;i++)              /* Change in fix end mom when vertmem are present */
	    {
		  jointfixendmom[0][1][confmemtopresentjoint[i]]=jointfixendmom[0][1][confmemtopresentjoint[i]]+vertfixendmomtotop[0][1][i];
		  /*jointfixendmom[0][2][confmemtopresentjoint[i]]=10;*/
	    }    

	if(confportalorbuildstr==2)             /*special arrangements to rf when portal frame */
	{
	  if(conffixright==1)
	  {
	    rfvaluetobeamstoleftofjoint[0][storeys+tempconf][baysinplanexy+1]=0;
	  }
	  if(conffixleft==1)
	  {
	    rfvaluetobeamstorightofjoint[0][1][1]=0;
	  }
	 /* if(confrightoh==1)
	  {
	    jointfixendmom[0][1][baysinplanexy]=jointfixendmom[0][1][baysinplanexy]-(0.5*jointfixendmom[0][1][baysinplanexy+1]);
	    jointfixendmom[0][1][baysinplanexy+1]=0;
	  }
	  if(confleftoh==1)
	  {
	    jointfixendmom[0][1][2]=jointfixendmom[0][1][2]-(0.5*jointfixendmom[0][1][1]);
	  }  */
	    printf("\n First R.F Val is %f\n",rfvaluetobeamstorightofjoint[0][1][1]);
	}
       /*Finding M.dash Moments*/
	  /*  for(j=1;j<storeys+1+tempconf;j++)
	    {
		for(k=1;k<baysinplanexy+2;k++)
		{
			printf("For Joint %d \n\n",k);
			printf("left  %.2f + %.2f + %.2f \n",mdashmomforbeamtorightside[0][j][k-1],mdashmomforcolumntowardstop[0][j-1][k],mdashmomforcolumntowardsbottom[0][j+1][k]));	    
			printf("right %.2f + %.2f + %.2f \n",mdashmomforbeamtoleftside[0][j][k]+mdashmomforcolumntowardstop[0][j-1][k]+mdashmomforcolumntowardsbottom[0][j+1][k]));
			mdashmomforcolumntowardstop[0][j][k]=(rfvaluetobeamstotopofjoint[0][j][k])*((jointfixendmom[0][j][k])+(mdashmomforbeamtoleftside[0][j][k-1]+mdashmomforbeamtorightside[0][j][k+1]+mdashmomforcolumntowardsbottom[0][j-1][k]));
			mdashmomforcolumntowardsbottom[0][j][k]=(rfvaluetobeamstobottomofjoint[0][j][k])*((jointfixendmom[0][j][k])+(mdashmomforbeamtoleftside[0][j][k-1]+mdashmomforbeamtorightside[0][j][k+1]+mdashmomforcolumntowardstop[0][j][k]));
   		}
	    }*/
	for(i=0;i<5;i++)
	{
	    for(j=1;j<storeys+1+tempconf;j++)
	    {
		for(k=1;k<baysinplanexy+2;k++)
		{
			mdashmomforbeamtoleftside[0][j][k]=(rfvaluetobeamstoleftofjoint[0][j][k])*((jointfixendmom[0][j][k])+(mdashmomforbeamtorightside[0][j][k-1]+mdashmomforcolumntowardstop[0][j+1][k]+mdashmomforcolumntowardsbottom[0][j-1][k]+mdashmomforbeamtoleftside[0][j][k+1]));	    
			mdashmomforbeamtorightside[0][j][k]=(rfvaluetobeamstorightofjoint[0][j][k])*((jointfixendmom[0][j][k])+(mdashmomforbeamtoleftside[0][j][k+1]+mdashmomforcolumntowardstop[0][j+1][k]+mdashmomforcolumntowardsbottom[0][j-1][k]+mdashmomforbeamtorightside[0][j][k-1]));
			mdashmomforcolumntowardstop[0][j][k]=(rfvaluetobeamstotopofjoint[0][j][k])*((jointfixendmom[0][j][k])+(mdashmomforbeamtoleftside[0][j][k+1]+mdashmomforbeamtorightside[0][j][k-1]+mdashmomforcolumntowardsbottom[0][j-1][k]+mdashmomforcolumntowardstop[0][j+1][k]));
			mdashmomforcolumntowardsbottom[0][j][k]=(rfvaluetobeamstobottomofjoint[0][j][k])*((jointfixendmom[0][j][k])+(mdashmomforbeamtoleftside[0][j][k+1]+mdashmomforbeamtorightside[0][j][k-1]+mdashmomforcolumntowardstop[0][j+1][k]+mdashmomforcolumntowardsbottom[0][j-1][k]));
   		}
	    }
	}
      /*Finding Final End Moments*/
	
	    for(j=1;j<storeys+1+tempconf;j++)
	    {
		for(k=1;k<baysinplanexy+2;k++)
		{
			finalendmomtoleftsideofbeam[0][j][k]=((finalfixendmomtorightside[0][j][k-1])+(2*(mdashmomforbeamtoleftside[0][j][k]))+mdashmomforbeamtorightside[0][j][k-1]);	    
			finalendmomtorightsideofbeam[0][j][k]=((finalfixendmomtoleftside[0][j][k])+(2*(mdashmomforbeamtorightside[0][j][k]))+mdashmomforbeamtoleftside[0][j][k+1]);
			finalendmomtotopsideofcolumn[0][j][k]=(2*(mdashmomforcolumntowardstop[0][j][k]))+(mdashmomforcolumntowardsbottom[0][j-1][k]);
			finalendmomtobottomsideofcolumn[0][j][k]=(2*(mdashmomforcolumntowardsbottom[0][j][k]))+(mdashmomforcolumntowardstop[0][j+1][k]);
   		}
	    }
          /* Final end moment changed due to vert member */
	    for(i=1;i<numofvertmem+1;i++)              
	    {
		  finalendmomtobottomsideofcolumn[0][1][confmemtopresentjoint[i]]=finalendmomtobottomsideofcolumn[0][1][confmemtopresentjoint[i]]+vertfixendmomtotop[0][1][i];
	    }
       } /*-1*/
 /* ---------------------------------------------------------------------------------------------------------- */
   /*Printing Executed Values*/
      /*Printing for Fix End Moments*/
       printf("Left side Fix End Moments are\n\n");

	 for(j=1;j<storeys+1+tempconf;j++)
	  {
	       for(k=1;k<baysinplanexy+1;k++)
	       {
		   for(i=1;i<numofpointloads[0][j][k]+1;i++)
		   {
			printf("  %f  ",fixendmomduetopointloadtoleftjoint[0][j][k][i]);
		   }
		   printf("\n\n");
	       }
	  }
     printf("Right side Fix End Moments are\n\n");
	
	 for(j=1;j<storeys+1+tempconf;j++)
	  {
	       for(k=1;k<baysinplanexy+1;k++)
	       {
		   for(i=1;i<numofpointloads[0][j][k]+1;i++)
		   {
			printf("  %f  ",fixendmomduetopointloadtorightjoint[0][j][k][i]);
		   }
		   printf("\n\n");
	       }
	  }
	getch();
	clrscr();
	printf("Your UDL are\n");
	for(j=1;j<storeys+1+tempconf;j++)
	{
	       for(k=1;k<baysinplanexy+1;k++)
	       {
		    printf("  %f  ",loadvalplanexy[0][j][k]);
			
		}
		printf("\n\n");
	}
	printf("Fixed End Moments due to UDL are as follows\n\n");
	for(j=1;j<storeys+1+tempconf;j++)
	{
	        for(k=1;k<baysinplanexy+1;k++)
		{
		     printf("  %.2f ,  %.2f    -  ", fixendmomduetoudltoleftpointforallbeamudl[0][j][k],fixendmomduetoudltorightpointforallbeamudl[0][j][k]);
		}
		printf("\n\n");
	} 
	getch();
	clrscr();
	printf("Final Fix End Moments are \n\n"); 
	for(j=1;j<storeys+1+tempconf;j++)
	{
	        for(k=1;k<baysinplanexy+1;k++)
		{
		     printf("  %.2f ,  %.2f   - ",finalfixendmomtoleftside[0][j][k],finalfixendmomtorightside[0][j][k]);
		}
		printf("\n\n");
	} 

     /*Printing Values for k,sigma k & rotation factor*/
	getch();
	clrscr();
	printf("K Value for BEAMs are\n\n");
	for(j=1;j<storeys+1+tempconf;j++)
	{
	       for(k=1;k<baysinplanexy+1;k++)
	       {
			printf("  %f  ",kvaluetobeams[0][j][k]);
	       }
		printf("\n\n");
	}
	printf("K Value for COLUMNS are\n\n");
	 for(j=1;j<storeys+1+tempconf;j++)
	{

		for(k=1;k<baysinplanexy+2;k++)
		{			       
			printf("  %f  ",kvaluetocolumns[0][j][k]);
		}
		printf("\n\n");
	} 
	printf("Sigma k values are \n\n");
	for(j=1;j<storeys+1+tempconf;j++)
	{
	      for(k=1;k<baysinplanexy+2;k++)
	      {
		     printf("  %f  ",sigmakval[0][j][k]);
	      }
	      printf("\n\n");
	      getch();
	}
	getch();
	clrscr();
	printf("RF Values are\n");
	    i=0;
	    for(j=1;j<storeys+1+tempconf;j++)
	    {
		for(k=1;k<baysinplanexy+2;k++)
		{

		     printf("Rotation Factor for joint %c -\n\n",name+i);
		     printf("     %.3f        Joint Fix End Moment  \n",rfvaluetobeamstotopofjoint[0][j][k]);
		     printf(" %.3f * %.3f   -    %.2f \n",rfvaluetobeamstoleftofjoint[0][j][k],rfvaluetobeamstorightofjoint[0][j][k],jointfixendmom[0][j][k]);
		     printf("     %.3f    \n\n",rfvaluetobeamstobottomofjoint[0][j][k]);
		     i++;
		     getch();
		}
	    }
	printf("M.dash Values are\n");
	    for(j=1;j<storeys+1+tempconf;j++)
	    {
		for(k=1;k<baysinplanexy+2;k++)
		{
			printf("    %.2f  \n",mdashmomforcolumntowardstop[0][j][k]);	    
			printf(" %.2f    %.2f \n",mdashmomforbeamtoleftside[0][j][k],mdashmomforbeamtorightside[0][j][k]);
			printf("    %.2f  \n",mdashmomforcolumntowardsbottom[0][j][k]);
			getch();
   		}
		printf("\n\n");
	    }
	   printf("Mdash to top %f \n",mdashmomforcolumntowardstop[0][2][2]);
	getch();
	clrscr();
	    printf("Final End Moments Are -");
	    i=0;
	    for(j=1;j<storeys+1+tempconf;j++)
	    {
		for(k=1;k<baysinplanexy+2;k++)
		{
			printf("At Joint %c \n\n",65+i);
			printf("     %.2f     \n",finalendmomtotopsideofcolumn[0][j][k]);
			printf("  %.2f    %.2f\n",finalendmomtoleftsideofbeam[0][j][k],finalendmomtorightsideofbeam[0][j][k]);
			printf("     %.2f   \n\n",finalendmomtobottomsideofcolumn[0][j][k]);
			i++;
			getch();
   		}
	    }
 /*GRAPH includer*/
    {
	storeylength[0]=0;
	for(i=1;i<storeys+1;i++)
	{
	   totalstoreylength=totalstoreylength+storeylength[i];
	}
	for(i=1;i<baysinplanexy+1;i++)
	{
	   totalbaylength=totalbaylength+baylengthplanexy[i];
	}
	/*for(i=1;i<baysinplanexy+1;i++)    /* if this loop not commented Taster3 val in next line changes from initial value */
	/*
	{
		baylength[i]=baylengthplanexy[i];
	}  */
        printf("Taster3 %d \n",ptloadonvertmember[0][1][confmemtopresentjoint[1]]);
	if(confportalorbuildstr==2)                 /* IF this is not given than "divide by zero" error shown in case of continous beams */
	{
	   totalstoreylength=0.5;
	}
	printf("Total height = %f\n",totalstoreylength);
	getch();
	storeyscale=400/totalstoreylength;
	bayscale=400/totalbaylength;
	scale=storeyscale;
	if(totalstoreylength<totalbaylength)
	{
	   scale=bayscale;
	}
	for(i=1;i<storeys+1;i++)
	{
		storeylengthchange[i]=storeylength[i]*scale;
	}
	for(i=1;i<baysinplanexy+1;i++)
	{
		baylengthchange[i]=baylengthplanexy[i]*scale;
	}
	printf("scale is %f",scale);
	getch();
	initgraph(&driver,&mode,"\\tc\\bgi");

      /* Printing BEAMS */
	setcolor(RED);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	lerftohlengthchange=leftohlength*scale;
	if(confportalorbuildstr==1)
	{
	  for(i=1;i<storeys;i++)
	  {
	   line(50,60+graphaddforstorey+storeylengthchange[i],50+(totalbaylength*scale),60+graphaddforstorey+storeylengthchange[i]);
	   graphaddforstorey=graphaddforstorey+storeylengthchange[i];
	  }
	 graphaddforstorey=graphaddforstorey+storeylengthchange[storeys];
	 line(50,60,50+totalbaylength*scale,60);
	}
	if(confportalorbuildstr==2)
	{
	   line(50+lerftohlengthchange,60,(50+totalbaylength*scale)+lerftohlengthchange,60);
	}
	outtextxy(500,20,"TOP STOREY");
	if(confportalorbuildstr==1)
	{
	    setcolor(WHITE);
	    line(10,graphaddforstorey+storeylengthchange[storeys+1]+60+incasecontbeam,630,graphaddforstorey+storeylengthchange[storeys+1]+60+incasecontbeam);
	}
	graphaddforbay=0;
      /* Printing COLUMNs */
	setcolor(GREEN);
	if(confportalorbuildstr==1)
	{
	 for(i=1;i<baysinplanexy+1;i++)
	 {
	   line(50+graphaddforbay+baylengthchange[i],60,50+graphaddforbay+baylengthchange[i],60+graphaddforstorey+storeylengthchange[storeys+1]);
	   graphaddforbay=graphaddforbay+baylengthchange[i];
	 }
	 line(50,60,50,60+(totalstoreylength*scale));
	}
      /*  Printing Vertical members in portal frames */
	if(confportalorbuildstr==2)
	{
	   graphaddforbay=0;
	   for(i=1;i<baysinplanexy+2;i++)
	   {
		line(50+graphaddforbay+baylengthchange[i]+lerftohlengthchange,60,50+graphaddforbay+baylengthchange[i]+lerftohlengthchange,60+8);
		//printf("Final %d \n",i);                     /* del */
		for(kl=1;kl<baysinplanexy+2;kl++)
		{
		    printf(" %d ",vertpresencetojoint[kl]);
		}
		printf("\n");
		if((vertpresencetojoint[i+1])==1)
		{
		 line(50+graphaddforbay+baylengthchange[i]+lerftohlengthchange,60,50+graphaddforbay+baylengthchange[i]+lerftohlengthchange,60+(columnlength[0][1][i+1]*scale));
		 setcolor(WHITE);
		 line(50+graphaddforbay+baylengthchange[i]+lerftohlengthchange-8,60+(columnlength[0][1][i+1]*scale),50+graphaddforbay+baylengthchange[i]+lerftohlengthchange+8,60+(columnlength[0][1][i+1]*scale));
		 setcolor(GREEN);
		}
	      /* Printing Loads on vert members */
		//key=2;            /* del */
		if((i+1)==(confmemtopresentjoint[key]))
		{
		  //printf(" presence %d \n",confmemtopresentjoint[key]);
		  //(" ptload  %d  \n",ptloadonvertmember[0][1][confmemtopresentjoint[key]]);
		  getch();
		  for(j=1;j<(ptloadonvertmember[0][1][confmemtopresentjoint[key]])+1;j++)
		  {
		   line(50+graphaddforbay+baylengthchange[i]+lerftohlengthchange+2,60+(scale*horloaddist[0][0][key][j]),50+graphaddforbay+baylengthchange[i]+lerftohlengthchange+10,60+(scale*horloaddist[0][0][key][j]));
		  }
		  key=key+1;
		  getch();
		}
		graphaddforbay=graphaddforbay+baylengthchange[i];
		outtextxy(300,20,"TOP STOREY");
	   }
	   line(50+lerftohlengthchange,60,50+lerftohlengthchange,60+8);
	} 

	setcolor(BLUE);
	graphaddforbay=0;
	graphaddforstorey=0;
      /* Including Graphics to show udl */
	for(j=1;j<storeys+1+tempconf;j++)
	{
           for(k=1;k<baysinplanexy+2;k++)
	   {
		if(loadtypeplanexy[0][j][k]==0)
		 line(50+graphaddforbay+lerftohlengthchange,55+graphaddforstorey+storeylengthchange[j-1],50+graphaddforbay+baylengthchange[k]+lerftohlengthchange,55+graphaddforstorey+storeylengthchange[j-1]);       	
	      /* Printing point loads */
		for(int ptl=1;ptl<numofpointloads[0][j][k]+1;ptl++)
		{
		     setcolor(YELLOW);
		     line(50+graphaddforbay+(pointloaddistance[0][j][k][ptl]*scale)+lerftohlengthchange,40+graphaddforstorey+storeylengthchange[j-1],50+graphaddforbay+(pointloaddistance[0][j][k][ptl]*scale)+lerftohlengthchange,53+graphaddforstorey+storeylengthchange[j-1]);
		}
		graphaddforbay=graphaddforbay+baylengthchange[k];
		setcolor(BLUE);
	   }
	   graphaddforbay=0;
	   graphaddforstorey=graphaddforstorey+storeylengthchange[j-1];
	   rightohlengthchange=rightohlength*scale;
	   if((lerftohlengthchange!=0)||(rightohlengthchange!=0))
	   {
		setcolor(RED);
		line(50,60,50+lerftohlengthchange,60);
		line(50+(totalbaylength*scale)+lerftohlengthchange,60,50+(totalbaylength*scale)+lerftohlengthchange+rightohlengthchange,60);
	   }       	
	}
	getch();
	closegraph();
	exit (0);
    }  /* GRAPHER END */
	getch();
}

