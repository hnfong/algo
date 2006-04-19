program ShellSort;
var
  n : longint;
  a : array[1..300000] of longint;
  d : longint;
  i , j , k , m : longint;
begin
	i := 0;
	while not eof do begin
	inc(i);
    readln(a[i]);
    end; n := i;

  d := n;
  while d > 1 do
  begin
    d := d div 3 + 1;
    for j := 1 to n do
    begin
      m := j;
      k := a[m];
      while (m-d>=1) and (a[m-d]>k) do
      begin
        a[m] := a[m-d];
        m := m - d;
      end;
      a[m] := k;
    end;
  end;

  for i := 1 to n do writeln(a[i]);
end.
