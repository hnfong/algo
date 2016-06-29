program p104;
{
	@JUDGE_ID:  20044WC 104 PASCAL "DaP/DyP"
	DUNNO HOW TO WARSHALL WITH LOOPS AR!!
}
label breakall;
label nextdata;
var
	i,j,k : longint;
	d : array[1..20,1..20] of real;
	w : array[1..20,1..20] of real; { later change to longint }
	l : array[1..20,1..20] of longint;
	bt : array[1..20,1..20] of longint;
	n : longint;
	t : longint; { max length threshold }
	tmpclen : longint;
	bestcycle : longint;
	besttrack : array[1..20] of longint;
procedure backtrack(a,b:longint);
begin
	if (a = 0) then begin
		exit;
	end;
	if (b = 0) then begin
		write(a, ' ');
		exit;
	end;
	backtrack(a,bt[a,b]);
	backtrack(bt[a,b],b);
end;

begin
	while not eof do begin
		readln(n);
		fillchar(d,sizeof(d),0);
		for i := 1 to n do begin
			for j := 1 to n do begin
				if i = j then begin
					d[i,j] := 1;
				end else begin
					read(d[i,j]);
				end;
			end;
			readln;
		end;
		
		writeln('**********');
		for t := 1 to n do begin
			{
			writeln('t = ', t);}
			fillchar(bt,sizeof(bt),0);
			fillchar(w,sizeof(w),0);
			fillchar(l,sizeof(l),0);

			{ reinit the length table }
			for i := 1 to n do
				for j := 1 to n do
					l[i,j] := 1;

			{ reinit the table }
			for i := 1 to n do
				for j := 1 to n do
					w[i,j] := d[i,j];
	
			for k := 1 to n do
			for i := 1 to n do
			for j := 1 to n do begin
				if (i=k) or (k=j) then continue;
				if l[i,k] + l[k,j] > t then continue;
				if w[i,k]*w[k,j] > w[i,j] then begin
					w[i,j] := w[i,k]*w[k,j];
					l[i,j] := l[i,k]+l[k,j];
					bt[i,j] := k;
					if (i=j) then begin
						if w[i,j] > 1.01 then begin
							writeln(w[i,j]:0:4, ' ',n);
							goto breakall;
						end;
						l[i,j] := 1000000000;
						writeln(i,' ',k,' ',j);
					end;
				end;
			end;
			breakall:
			writeln(w[1,1]);
			for i := 1 to n do begin
				if w[i,i] > 1.01 then begin
					{backtrack(i,i);}
					writeln(i);
					goto nextdata;
				end;
			end;
			{
			for i := 1 to n do begin
				for j := 1 to n do
					write(bt[i,j]);
				writeln;
			end;
			writeln;
			}
		end;
		writeln('no arbitrage sequence exists');
		nextdata:
		exit;
	end;
end.

