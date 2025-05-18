program program3;
uses math;
type
coord = record
	x : longint;
	y : longint;
	v : boolean;
end;

var
	b, c, i,j,k,l,m,n,t,u,v : longint;
	tmp : coord;
	a : array[1..1000] of coord;
	a2 : array[1..1000] of longint;
	ba : double; lba, ta : double;
begin
	assign(input, 'input3.txt');
	reset(input);
	readln(n);
	for i := 1 to n do begin
		a[i].v := false;
		read(a[i].x);
		read(a[i].y);
		readln;
	end;
	close (input);
	
	for i := 1 to n - 1 do 
		for j := n - 1 downto i do 
			if a[j].x > a[j+1].x then begin
				tmp := a[j];
				a[j] := a[j+1];
				a[j+1] := tmp;
			end;
	c := 1;
	j := 1;
	a2[1] := 1;
	a[1].v := false;
	m := 1;
	lba := 1000;
	while c > 0 do begin
		ba := -1000;
		writeln('run ', a[c].x, ' ' , a[c].y);
		for i := 1 to n do begin
			if (a[i].v = false) then begin
				ta := arctan2(a[i].x - a[c].x, a[i].y - a[c].y );
				if (ta > ba) and (ta < lba) or ((i = 1) and (abs(ta - 3.141592653589793) < 0.0000001)) then begin
					ba := ta;
					b := i;
				end;
			end;
		end;
		c := b;
		a[c].v := true;
		j:=j+1;
		a2[j] := c;
		lba := ba;
		if (round(ba) = -1000) or (c = 1) then break;
	end;

	ta := 0;
	for i := 2 to j do begin
		ta := ta+ sqrt(sqr(a[a2[i]].x - a[a2[i-1]].x) + sqr(a[a2[i]].y - a[a2[i-1]].y)) ;
	end;
	writeln(ta:0:2);
	for i := 1 to j do begin
		writeln(a[a2[i]].x, ' ', a[a2[i]].y, a[a2[i]].v);
	end;
end.

