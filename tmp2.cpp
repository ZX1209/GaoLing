gotoxy(int x,int y,int dir)
{
	if(end)  set(x,y);
	
	
	
	for(x<limit,x++)
	{
		if(state(x,y) not continue) break;
		for(y<limit,y++)
		{
			
			if(state(x,y) not continue) break;
			gotoxy(x,y,nextdir);
		}
	}
}















