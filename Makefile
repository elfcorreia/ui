test_janela: test_janela.cpp
	g++ `pkg-config --cflags gtk4` uigtk.cpp test_janela.cpp `pkg-config --libs gtk4`