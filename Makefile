.PHONY: clean All

All:
	@echo "----------Building project:[ BigInteger - Debug ]----------"
	@"$(MAKE)" -f  "BigInteger.mk"
clean:
	@echo "----------Cleaning project:[ BigInteger - Debug ]----------"
	@"$(MAKE)" -f  "BigInteger.mk" clean
