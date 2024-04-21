USER = foureyez 
KEYBOARDS = sofle_choc 

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	git submodule update --init --recursive
	git submodule update --remote
	# git submodule foreach make git-submodule 

	# cleanup old symlinks
	rm -rf qmk_firmware/keyboards/$@/keymaps/$(USER)
	rm -rf qmk_firmware/users/$(USER)

	# add new symlinks
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$@/keymaps/$(USER)
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)

	# run lint check
	# cd qmk_firmware; qmk lint -km $(USER) -kb $(NAME_$@)

	# run build
	make BUILD_DIR=$(shell pwd)/build -j1 -C qmk_firmware $@:$(USER)

clean:
	rm -rf ./qmk_firmware/
