# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 12:36:46 by luis-ffe          #+#    #+#              #
#    Updated: 2025/01/06 08:41:25 by luis-ffe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GRN = \033[0;32m
YEL = \033[0;33m
BLU = \033[0;34m
MAG = \033[0;35m
CYN = \033[0;36m
WHT = \033[0;37m
RES = \033[0m

C++ = c++
CPPFLAGS = -Werror -Wall -Wextra -g -std=c++98

NAME = mutant
RM = rm -rf
SDIR := src
ODIR := obj

SOURCES = main.cpp

OBJECTS := $(patsubst %.cpp,$(ODIR)/%.o,$(SOURCES))

TOTAL_FILES := $(words $(SOURCES))
COMPILED_FILES := $(shell if [ -d "$(ODIR)" ]; then find $(ODIR) -name "*.o" | wc -l; else echo 0; fi)

all : ${NAME}

${NAME} : ${OBJECTS}
	@${C++} ${CPPFLAGS} ${OBJECTS} -o ${NAME}
	@printf "$(GRN)➾ Compilation progress: $$(echo "$(shell find $(ODIR) -name "*.o" | wc -l) $(TOTAL_FILES)" | awk '{printf "%.2f", $$1/$$2 * 100}')%%$(RES)\r"
	@printf "\n$(GRN)➾ ${NAME} created$(RES)"
	@printf "\n"

$(ODIR)/%.o: $(SDIR)/%.cpp | $(ODIR)
	@mkdir -p $(dir $@)
	@$(C++) $(CPPFLAGS) -c -o $@ $<
	@printf "$(GRN)➾ Compilation progress: $$(echo "$(shell find $(ODIR) -name "*.o" | wc -l) $(TOTAL_FILES)" | awk '{printf "%.2f", $$1/$$2 * 100}')%%$(RES)\r"

$(ODIR):
	@mkdir -p $@	

clean :
	@${RM} ${OBJECTS}
	@${RM} ${ODIR}

fclean : clean
	@${RM} ${NAME}
	@printf "${RED}➾ ${NAME} deleted\n ${RES}"

re : fclean all