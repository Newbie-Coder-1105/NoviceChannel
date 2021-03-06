#include<iostream>
#include<string>
#include<cmath>

#include "data_interface.h"
#include "printdata.h"

using namespace std;

template<class Type>
int Create4D_Array(Type *****pResult, int a, int b, int c, int d)
{
    Type ****p = new Type ***[a];
    for(int i = 0; i < a; i++)
    {
        p[i] = new Type **[b];
        for(int j = 0; j < b; j++)
		{
			p[i][j] = new Type *[c];
			for(int k =0; k < c; k++)
			{
				p[i][j][k] = new Type [d];
			}
		}
		
    }
    *pResult = p;
    return  0;
}

template<class Type>
int Create2D_Array(Type ***pResult, int a, int b)
{
    Type **p = new Type *[a];
    for(int i = 0; i < a; i++)
    {
        p[i] = new Type [b];	
    }
    *pResult = p;
    return  0;
}

int main ()
{
	cout<<"reading is starting"<<endl;
	size_t I_RECS, I_LATS, I_LONS, I_LVLS;
	
	float* zpos = NULL;
	zpos = new float[I_LVLS];
	float* ypos = NULL;
	ypos = new float[I_LATS];
	float* xpos = NULL;
	xpos = new float[I_LONS];
		
	double tpos[15];

	short ****air = NULL;
	short ****omeg = NULL;
	short ****uwnd = NULL;
	short ****vwnd = NULL;
	short ****rhum = NULL;
	short **dem = NULL;
  	
	Create4D_Array(&air, I_RECS, I_LVLS, I_LATS, I_LONS);
	Create4D_Array(&omeg, I_RECS, I_LVLS, I_LATS, I_LONS);	
	Create4D_Array(&uwnd, I_RECS, I_LVLS, I_LATS, I_LONS);	
	Create4D_Array(&vwnd, I_RECS, I_LVLS, I_LATS, I_LONS);	
	Create4D_Array(&rhum, I_RECS, I_LVLS, I_LATS, I_LONS);
	Create2D_Array(&dem, I_LATS, I_LONS) ;

	Data_handle_read datafile;
	datafile.data_4D_read( I_RECS, I_LVLS, I_LATS, I_LONS, zpos, ypos, xpos, tpos, &air);
	datafile.data_4D_read( I_RECS, I_LVLS, I_LATS, I_LONS, zpos, ypos, xpos, tpos, &omeg);
	datafile.data_4D_read( I_RECS, I_LVLS, I_LATS, I_LONS, zpos, ypos, xpos, tpos, &uwnd);
	datafile.data_4D_read( I_RECS, I_LVLS, I_LATS, I_LONS, zpos, ypos, xpos, tpos, &vwnd);
	datafile.data_4D_read( I_RECS, I_LVLS, I_LATS, I_LONS, zpos, ypos, xpos, tpos, &rhum);
		
	datafile.data_2D_read(I_LATS, I_LONS, ypos, xpos, &dem);
  
  	std::cout<<"working  irecs = " << I_RECS << "  I_LVLS = "<< I_LVLS<<"  I_LATS = "<< I_LATS <<"  I_LONS = " << I_LONS <<'\n' ;
	
	Data_Print dp;
	dp.print_4D_data(I_RECS, I_LVLS, I_LATS, I_LONS, zpos, ypos, xpos, tpos, &air );
	dp.print_4D_data(I_RECS, I_LVLS, I_LATS, I_LONS, zpos, ypos, xpos, tpos, &omeg );
	dp.print_4D_data(I_RECS, I_LVLS, I_LATS, I_LONS, zpos, ypos, xpos, tpos, &uwnd );
	dp.print_4D_data(I_RECS, I_LVLS, I_LATS, I_LONS, zpos, ypos, xpos, tpos, &vwnd );
	dp.print_4D_data(I_RECS, I_LVLS, I_LATS, I_LONS, zpos, ypos, xpos, tpos, &rhum );
	
	dp.print_2D_data(I_LATS, I_LONS, ypos, xpos, &dem) ;
	
	return 0;
		
}
