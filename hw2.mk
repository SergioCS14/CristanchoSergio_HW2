Resultados_hw2.pdf : Resultados_hw2.tex 2_Signal.pdf 2_FourierSignal.pdf 2_Espectrogramas.pdf 2_Temblor.pdf 2_FourierTemblor.pdf 2_EspectrogramaTemblor.pdf 3_Maximos.pdf 3_Edificio_bono.pdf 3_Edificio_bono1.pdf
	pdflatex Resultados_hw2.tex
2_Signal.pdf 2_FourierSignal.pdf 2_Espectrogramas.pdf 2_Temblor.pdf 2_FourierTemblor.pdf 2_EspectrogramaTemblor.pdf : Fourier.py signal.dat signalSuma.dat temblor.txt
	python Fourier.py
3_PrimerEdificio 3_Maximos.pdf 3_Edificio_omega1.pdf 3_Edificio_omega2.pdf 3_Edificio_omega3.pdf 3_Edificio_bono.pdf 3_Edificio_bono1.pdf: Plots_hw2.py 3_MaximoP1.dat 3_MaximoP2.dat 3_MaximoP3.dat 3_Piso1.dat 3_Piso2.dat 3_Piso3.dat 3_Piso1_omega1.dat 3_Piso2_omega1.dat 3_Piso3_omega1.dat 3_Piso1_omega2.dat 3_Piso2_omega2.dat 3_Piso3_omega2.dat 3_Piso1_omega3.dat 3_Piso2_omega3.dat 3_Piso3_omega3.dat 3_Piso1_bono.dat 3_Piso2_bono.dat 3_Piso3_bono.dat 3_Piso1_bono1.dat 3_Piso2_bono1.dat 3_Piso3_bono1.dat
	python Plots_hw2.py
3_MaximoP1.dat 3_MaximoP2.dat 3_MaximoP3.dat 33_Piso1.dat 3_Piso2.dat 3_Piso3.dat 3_Piso1_omega1.dat 3_Piso2_omega1.dat 3_Piso3_omega1.dat 3_Piso1_omega2.dat 3_Piso2_omega2.dat 3_Piso3_omega2.dat 3_Piso1_omega3.dat 3_Piso2_omega3.dat 3_Piso3_omega3.dat: a.out 
	./a.out
a.out : Edificio.cpp
	g++ -std=c++11 Edificio.cpp
3_Piso1_bono.dat 3_Piso2_bono.dat 3_Piso3_bono.dat 3_Piso1_bono1.dat 3_Piso2_bono1.dat 3_Piso3_bono1.dat : b.x
	./b.x
b.x : Edificio_bono.cpp
	g++ -o b.x Edificio_bono.cpp
