int item::randitem(){
	int sum=0,num=0;
	for(int i = 0;i<sizeof(itemNameList);i++){
		sum+=itemlist[i].rate;
		}
	num =rand()%sum+1;
	int stack = 0;
		for(int k=0;k<sizeof(itemNameList);k++)
		{		
			if(num > stack && num<= stack+itemlist[k].rate )
			{
				return k;
			}
			stack+=itemlist[k].rate;
		}
}
