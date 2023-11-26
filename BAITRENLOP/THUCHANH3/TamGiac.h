#pragma once
#ifndef TAMGIAC_H
#define TAMGIAC_H
#include "Diem.h"
class TAMGIAC {
	private: 
		DIEM A,B,C;
		static int dem;
	public:
		~TAMGIAC();
		TAMGIAC();
		TAMGIAC(const DIEM&, const DIEM&, const DIEM&);
		TAMGIAC (double, double, double, double, double ,double);
		DIEM GetA() const ;
		DIEM GetB() const ;
		DIEM GetC() const ;
		static int GetDem();
		void SetA(const DIEM&);
		void SetB(const DIEM&);
		void SetC(const DIEM&);
		void SetABC(const DIEM&, const DIEM&, const DIEM&);
		void Nhap();
		void Xuat() const ;
		bool KiemTraHopLe() const ;
		string PhanLoai() const ;
		double TinhChuVi() const ;
		double TinhDienTich() const;
};
#endif