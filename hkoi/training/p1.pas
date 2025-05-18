program p1;
var
	i,j,k : longint;
	r : longint;
	a : array[1..5,1..5] of longint;
	c : array[1..5,1..5] of longint;
	t1,t2 : boolean;
	w1,w2 : boolean;
procedure dump;
var i,j,k : longint;
begin
	for i := 1 to 5 do begin
		for j := 1 to 5 do begin
			write(a[i,j]:3);
		end;
		writeln;
	end;
	writeln;
	for i := 1 to 5 do begin
		for j := 1 to 5 do begin
			write(c[i,j]:3);
		end;
		writeln;
	end;
	writeln;
end;

begin
	assign(input, 'bingo.in');
	reset(input);
{	assign(output, 'bingo.out');
	rewrite(output);}

	for i := 1 to 5 do begin
		for j := 1 to  5 do begin
			read(a[i,j]);
		end;
		readln;
	end;
	for i := 1 to 5 do begin
		for j := 1 to  5 do begin
			read(c[i,j]);
		end;
		readln;
	end;
	for k := 1 to 75 do begin
		readln(r);
		for i := 1 to 5 do begin
			for j := 1 to 5 do begin
				if a[i,j] = r then a[i,j] := -1;
				if c[i,j] = r then c[i,j] := -1;
			end;
		end;
		w1 := false;
		w2 := false;
		for i := 1 to 5 do begin
			t1 := false;
			t2 := false;
			for j := 1 to 5 do begin
				if a[i,j] >= 0 then t1 := true;
			end;
			for j := 1 to 5 do begin
				if c[i,j] >= 0 then t2 := true;
			end;
			if t1 = false then w1 := true;
			if t2 = false then w2 := true;
		end;
		for j := 1 to 5 do begin
			t1 := false;
			t2 := false;
			for i := 1 to 5 do begin
				if a[i,j] >= 0 then t1 := true;
			end;
			for i := 1 to 5 do begin
				if c[i,j] >= 0 then t2 := true;
			end;
			if t1 = false then w1 := true;
			if t2 = false then w2 := true;
		end;

		t1 := false;
		t2 := false;
		for i := 1 to 5 do begin
			if a[i,6-i] >= 0 then t1 := true;
			if c[i,6-i] >= 0 then t2 := true;
		end;
		if t1 = false then w1 := true;
		if t2 = false then w2 := true;

		t1 := false;
		t2 := false;
		for i := 1 to 5 do begin
			if a[i,i] >= 0 then t1 := true;
			if c[i,i] >= 0 then t2 := true;
		end;
		if t1 = false then w1 := true;
		if t2 = false then w2 := true;


		if (w1 = true) and (w2 = true) then begin dump; writeln('Draw Game'); exit; end;
		if w1 = true then begin writeln('Alan'); exit; end;
		if w2 = true then begin writeln('Candy'); exit; end;
	end;
	writeln('Draw Game');
	close(input);
	close(output);
end.

