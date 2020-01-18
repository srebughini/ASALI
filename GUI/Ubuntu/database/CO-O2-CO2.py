#	2*CO + O2 = 2*CO2	r=1*CO*O2	(heterogeneous)

from math import exp, pow
class kinetic:

	n = ["AR","CO","CO2","O2"]

	shet = [[0,-2,2,-1]]

	Nhet = 1
	Nhom = 0

	#Unit dimensions: kmol/m2/s
	def heterogeneous(self,T,x):
		r = [1*x[1]*x[3]]
		R = [0.]*4
		for i in range(0,4):
			for j in range(0,1):
				R[i]=R[i]+self.shet[j][i]*r[j]
		return R

	#Unit dimensions: kmol/m3/s
	def homogeneous(self,T,x):
		R = [0.]*4
		return R

	#Unit dimensions: kmol/m3/s
	def allHomogeneous(self,T,x):
		R = [0]*0*4
		c = 0
		return R

	#Unit dimensions: kmol/m2/s
	def allHeterogeneous(self,T,x):
		r = [1*x[1]*x[3]]
		R = [0]*1*4
		c = 0
		for i in range(0,4):
			for j in range(0,1):
				R[c] = self.shet[j][i]*r[j]
				c = c + 1
		return R

	#Unit dimensions: kmol/m3/s
	def netHom(self,T,x):
		r = [0]
		return r

	#Unit dimensions: kmol/m2/s
	def netHet(self,T,x):
		r = [1*x[1]*x[3]]
		return r

	def name(self):
		return self.n

	def NRhom(self):
		return self.Nhom

	def NRhet(self):
		return self.Nhet
