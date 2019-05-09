Resultados_hw2.pdf : Resultados_hw2.tex 2_Signal.pdf 2_FourierSignal.pdf 2_Espectrogramas.pdf 2_Temblor.pdf 2_FourierTemblor.pdf 2_EspectrogramaTemblor.pdf 3_Maximos.pdf
	pdflatex Resultados_hw2.tex
2_Signal.pdf 2_FourierSignal.pdf 2_Espectrogramas.pdf 2_Temblor.pdf 2_FourierTemblor.pdf 2_EspectrogramaTemblor.pdf : Fourier.py signal.dat signalSuma.dat temblor.txt
	python Fourier.py
3_PrimerEdificio 3_Maximos.pdf : Plots_hw2.py 3_MaximoP1.dat 3_MaximoP2.dat 3_MaximoP3.dat 3_Piso1.dat 3_Piso2.dat 3_Piso3.dat
	python Plots_hw2.py
3_MaximoP1.dat 3_MaximoP2.dat 3_MaximoP3.dat 3_Piso1.dat 3_Piso2.dat 3_Piso3.dat: a.out 
	./a.out
a.out : Edificio.cpp
	g++ Edificio.cpp