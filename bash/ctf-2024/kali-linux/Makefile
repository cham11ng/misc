# Compile scripts
compile:
	@shc -f first-flag.sh -o first-flag
	@shc -f second-flag.sh -o second-flag

# Clean the compiled files
clean:
	@rm -rf *.sh.x.c
	@rm -rf first-flag
	@rm -rf second-flag

# Compress to zip
compress:
	zip first-flag.zip first-flag
	zip second-flag.zip second-flag
