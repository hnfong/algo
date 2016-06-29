program p2023;
type a = array[1..30000] of longint;
var
	i,j,k,n,f,z : longint;
	w : array[1..30000] of longint;
	c : a;
procedure isort(e,f,x:longint);
var
        i,j,k : longint;
begin
        for i := e to f do begin
                j := i;
                k := w[j];
                while (j-x >= e) and (w[j-x] > k) do begin
                        w[j] := w[j-x];
                        dec(j,x);
                end;
                w[j] := k;
        end;
end;
procedure ssort(e,f:longint);
var k : longint;
begin
        k := n;
        while k <> 1 do begin
                k := k div 3 + 1;
                isort(e,f,k);
        end;
end;

begin
	fillchar(c,sizeof(c),0);
	fillchar(w,sizeof(w),0);
	readln(n);
	z := 0;
	for i := 1 to n do begin
		readln(w[i]);
		z := z + w[i];
	end;
	writeln(z/n:0:3);
	for i := 1 to n do begin inc(c[w[i]]); end;
	ssort(1,n);
	if n mod 2 = 1 then begin
		writeln(w[n div 2 + 1]);
	end else begin
		if (w[n div 2]+w[n div 2 + 1]) mod 2 = 1 then begin
			writeln((w[n div 2]+w[n div 2 + 1])/2:0:1);
		end else begin
			writeln((w[n div 2]+w[n div 2 + 1]) div 2);
		end;
	end;;
	{ mode }
	f := 0; k := 0;
	for i := 1 to 30000 do begin
		if c[i] > f then begin
			f := c[i];
			k := i;
		end;
	end;
	writeln(k);
	
end.

