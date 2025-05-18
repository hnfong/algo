program p1013;
const hc : array[1..12] of longint = (
		31,28,31,30,31,30,31,31,30,31,30,31
	);
type
	cus = record
		id : longint;
		free : double;
		pnet : double;
		time : longint;
		init : longint;
	end;
var
	i,j,k,m,n,z  : longint;
	w : array[1..20] of cus;
	ez,et,fz,ft : longint;
	swp : cus;
	ed,em,ey,eh,en,es : longint;
	fd,fm,fy,fh,fn,fs : longint;
function findcus(id:longint):longint;
var i : longint;
begin
	for i := 1 to m do begin if w[i].id = id then findcus := i; end;
end;

function calc(i:longint) : double;
var t : double;
begin
	t :=  (w[i].time div 60 - w[i].free )*w[i].pnet+w[i].init;
	if t < w[i].init then calc := w[i].init else calc := t;
end;
function leapyear(m,y:longint):boolean;
begin
	if (y mod 4 = 0) and (y <> 0) and (m = 2) then leapyear := true else leapyear := false;
end;
function zid(x:longint):string[10];
var i : longint; s : string[10];
begin	
	s := '';
	for i := 1 to 8 do begin
		s := chr((x mod 10)+48) + s;
		x := x div 10;
	end;
	zid := s;
end;

begin
	readln(m,n);
	for i := 1 to m do begin
		readln(w[i].id,w[i].free,w[i].pnet);
		if w[i].free = 100 then w[i].init := 80 else w[i].init := 50;
	end;
	for i := 1 to n do begin
		z := 0;
		readln(k,ez,et,fz,ft);
		ey := ez mod 100; ez := ez div 100;
		em := ez mod 100; ez := ez div 100;
		ed := ez mod 100;
		fy := fz mod 100; fz := fz div 100;
		fm := fz mod 100; fz := fz div 100;
		fd := fz mod 100;
		es := et mod 100; et := et div 100;
		en := et mod 100; et := et div 100;
		eh := et mod 100;
		fs := ft mod 100; ft := ft div 100;
		fn := ft mod 100; ft := ft div 100;
		fh := ft mod 100;
		inc(z,(fd-ed));
		if (em<>fm) then begin
			inc(z,hc[em]);
			if leapyear(em,ey) then inc(z);
		end;
		z := z*86400;
		z := z + (fh-eh)*3600;
		z := z + (fn-en)*60;
		z := z + (fs-es);
		if z mod 60 > 0 then begin
			z := ((z div 60) + 1) * 60;
		end;
		inc(w[findcus(k)].time,z);
	end;
	for i := 1 to m do begin
		for j := m downto 2 do begin
			if w[j].id < w[j-1].id then begin
				swp := w[j];
				w[j] := w[j-1];
				w[j-1] := swp;
			end;
		end;
	end;
	writeln('Account Number   Time Used         Amount');
	writeln('*****************************************');
	for i := 1 to m do begin
		writeln(zid(w[i].id), w[i].time div 60:18, calc(i):15:2 );
	end;
end.
