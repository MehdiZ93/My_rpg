LIBDIR	=	./lib

SRCDIR	=	./src

all:
	(cd $(LIBDIR); make all)
	(cd $(SRCDIR); make all)

clean:
	(cd $(LIBDIR); make clean)
	(cd $(SRCDIR); make clean)

fclean:
	(cd $(LIBDIR); make fclean)
	(cd $(SRCDIR); make fclean)

re:
	(cd $(LIBDIR); make re)
	(cd $(SRCDIR); make re)

.PHONY: all clean fclean re
