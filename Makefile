.PHONY: clean All

All:
	@echo "----------Building project:[ biginteger - Debug ]----------"
	@"$(MAKE)" -f  "biginteger.mk"
clean:
	@echo "----------Cleaning project:[ biginteger - Debug ]----------"
	@"$(MAKE)" -f  "biginteger.mk" clean
