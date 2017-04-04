int any_odd_one (unsigned x)
{
	if ((x & 0xAAAAAAAA) != 0)
	{
		return 1;
	}
	return 0;
}


