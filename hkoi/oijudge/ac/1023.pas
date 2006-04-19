program p1023;
var
	i,j,k : longint;
	n,m,c : longint;
	e,t : longint;
	negative:shortint;
begin
	readln(n,k);
	e := 99999999;
	negative := 0;
	for i := 1 to n do begin
		read(m);
		if abs(m-k) < e then begin
			if m-k < 0 then negative := 1;
			if m-k > 0 then negative := -1;
			e := abs(m-k);
			t := m;
		end;

		if (abs(m-k) = e) and (negative = 1) then begin
			if m-k < 0 then negative := 1;
			if m-k > 0 then negative := -1;
			e := abs(m-k);
			t := m;
		end;
	end;
	writeln(t);
end.
