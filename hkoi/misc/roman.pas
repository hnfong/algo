program roman;
{
	DECIMAL TO ROMAN CONVERSION PROGRAM
}
var
	n,i,j,k,l,m : longint;
	x : array[1..10, 1..20] of char;
	d : array[1..20] of longint;
	p : longint;
	dat : array [1..4,1..2] of char;
	dat2 : array ['A'..'Z'] of longint;
	o : longint;
	t : boolean;
begin
	dat[1,1] := 'I';	dat[1,2] := 'V';
	dat[2,1] := 'X';	dat[2,2] := 'L';
	dat[3,1] := 'C';	dat[3,2] := 'D';
	dat[4,1] := 'M';
	dat2['I'] := 1;		dat2['V'] := 5;
	dat2['X'] := 10; 	dat2['L'] := 50;
	dat2['C'] := 100;	dat2['D'] := 500;
	dat2['M'] := 1000;

	readln(n);
	for i := 1 to n do begin
		readln(x[i]);
	end;
	
	for i := 1 to n do begin
		for j:=1 to 20 do begin
			d[j] := 0;
		end;
		write(x[i], ' = ');
		if ord(x[i,1]) < 58 then begin
			{dec input}
			for j := 1 to 20 do begin
				if (ord(x[i,j]) < 48) or (ord(x[i,j]) > 57) then begin p := j ; break; end;
				d[j] := ord(x[i,j]) - 48;
			end;
			p := p - 1;
{			writeln;
			writeln('p is ' , p);}
			for j := 1 to p do begin
				if d[j] = 9 then begin write(dat[p-j+1,1], dat[p-j+2,1]); break; end;
				if d[j] = 4 then begin write(dat[p-j+1,1], dat[p-j+1,2]); break; end;
				if d[j] >= 5 then begin write(dat[p-j+1,2]); d[j] := d[j] - 5; end;
				for k := 1 to d[j] do write(dat[p-j+1,1]);
			end;
			writeln;
		end;

		if ord(x[i,1]) >= 65 then begin
			o := 0;
			{ roman }
			t := false;
			for j := 1 to 20 do begin
				if t then begin t:=false; continue; end;
				if (ord(x[i,j+1]) < 65) or (ord(x[i,j+1]) > 90) then begin o:=o+dat2[x[i,j]]; break; end;
				if dat2[x[i,j]] < dat2[x[i,j+1]] then  begin
					o := o+dat2[ x[i,j+1] ] - dat2[ x[i,j] ] ;
					t := true;
				end
				else o:=o+dat2[x[i,j]];
			end;
			writeln(o);
		end;
	end;
end.
