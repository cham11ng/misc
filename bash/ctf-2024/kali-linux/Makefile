# Compile scripts
compile:
	@shc -f first-half-flag.sh -o first-half-flag
	@shc -f second-half-flag.sh -o second-half-flag

# Clean the compiled files
clean:
	@rm -rf *.sh.x.c
	@rm -rf first-half-flag
	@rm -rf second-half-flag

# Compress to zip
compress:
	zip flag.zip first-half-flag second-half-flag
