// color.hpp

// author: Tiago Cavalcante Trindade
// version: 1.0.3
// email: 
// access: https://www.clubedohardware.com.br/forums/topic/1396899-tutorial-como-colocar-cor-no-c/

#pragma once

#include <iostream>

using namespace std;

namespace style {
	enum FOREGROUND {
		fBLACK = 30, /* letra preta */
		fRED, /* letra vermelha */
		fGREEN, /* letra verde */
		fYELLOW, /* letra amarela */
		fBLUE, /* letra azul */
		fMAGENTA, /* letra magenta */
		fCYAN, /* letra ciano */
		fWHITE, /* letra branca */
		fBLACKs = 90, /* letra preta estrondosa */
		fREDs, /* letra vermelha estrondosa */
		fGREENs, /* letra verde estrondosa */
		fYELLOWs, /* letra amarela estrondosa */
		fBLUEs, /* letra azul estrondosa */
		fMAGENTAs, /* letra magenta estrondosa */
		fCYANs, /* letra ciana estrondosa */
		fWHITEs, /* letra branca estrondosa */
	};
	enum BACKGROUND {
		bBLACK = 40, /* fundo preto */
		bRED, /* fundo vermelho */
		bGREEN, /* fundo verde */
		bYELLOW, /* fundo amarelo */
		bBLUE, /* fundo azul */
		bMAGENTA, /* fundo magenta */
		bCYAN, /* fundo ciano */
		bWHITE, /* fundo branco */
		bBLACKs = 100, /* fundo preto estrondoso */
		bREDs, /* fundo vermelho estrondoso */
		bGREENs, /* fundo verde estrondoso */
		bYELLOWs, /* fundo amarelo estrondoso */
		bBLUEs, /* fundo azul estrondoso */
		bMAGENTAs, /* fundo magenta estrondoso */
		bCYANs, /* fundo ciano estrondoso */
		bWHITEs /* fundo branco estrondoso */
	};
	enum STYLE {
		sRESET = 0, /* estilo de letra padrão */
		sBOLD, /* cor da letra fica mais forte */
		sUNDERLINE = 4, /* sublinhado */
		sINVERSE = 7, /* inverte a cor do fundo com a cor da letra */
	};
}

namespace color {
	/*escreve um texto em determinada cor*/
	void coutc(const char* text, style::FOREGROUND foreground) {
		cout << "[" << foreground << "m" << text << "[0m";
	}
	/*escreve um texto com determinada cor de fundo*/
	void coutc(const char* text, style::BACKGROUND foreground) {
		cout << "[" << foreground << "m" << text << "[0m";
	}
	/*escreve um texto com determinada estilo*/
	void coutc(const char* text, style::STYLE style) {
		cout << "[" << style << "m" << text << "[0m";
	}
	/*escreve um texto em determinada cor e com determinada cor de fundo*/
	void coutc(const char* text, style::FOREGROUND foreground,  style::BACKGROUND background) {
		cout << "[" << foreground << "m[" << background << "m" << text << "[0m";
	}
	/*escreve um texto em determinada cor e com determinado estilo*/
	void coutc(const char* text, style::FOREGROUND foreground, style::STYLE style) {
		cout << "[" << foreground << "m[" << style << "m" << text << "[0m";
	}
	/*escreve um texto com determinada cor de fundo e com determinado estilo*/
	void coutc(const char* text, style::BACKGROUND background, style::STYLE style) {
		cout << "[" << background << "m[" << style << "m" << text << "[0m";
	}
	/*escreve um texto em determinada cor e com determinada cor de fundo e em determinado estilo*/
	void coutc(const char* text, style::FOREGROUND foreground, style::BACKGROUND background, style::STYLE style) {
		cout << "[" << foreground << "m[" << background << "m[" << style << "m" << text << "[0m";
	}
}