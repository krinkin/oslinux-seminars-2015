
static void cat(const char *cmd, const char *comment) {
	FILE *p = NULL;
	char buf[BUFSIZ];
	
	p = popen(cmd,"r");
	
	printf("==== %s %s\n",comment,cmd);


	while (NULL != fgets(buf,BUFSIZ,p))
	{
		printf("%s",buf);
	}
	fclose(p);
}

