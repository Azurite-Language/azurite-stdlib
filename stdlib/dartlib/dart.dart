double Sum(List<double> a) {
  double S = 0;
  for (double i in a) S += i;
  return S;
}

double Minus(List<double> a) {
  if (a.length == 0) return 0;
  if (a.length == 1) return a[0] * -1;
  double S = a[0];
  for (int i = 1; i < a.length; i++) S -= a[i];
  return S;
}

double Mult(List<double> a) {
  if (a.length == 0) return 1;
  double S = a[0];
  for (int i = 1; i < a.length; i++) S *= a[i];
  return S;
}

double Div(List<double> a) {
  if (a.length == 0) return 1;
  double S = a[0];
  for (int i = 1; i < a.length; i++) S /= a[i];
  return S;
}

double float_of_bool(bool a) {
  return a ? 1.0 : 0.0;
}

bool bool_of_float(double a) {
  return a != 0;
}

bool bool_of_string(String a) {
  return !(a == "" ||
      a == "0" ||
      a == "0." ||
      a == "0.0" ||
      a == "False" ||
      a == "false");
}

String string_of_bool(bool a) {
  return a ? "true" : "false";
}

bool list_equal<T>(List<T> a) {
  if (a.length == 0) return true;
  T s = a[0];
  for (int i = 1; i < a.length; i++) {
    if (s != a[i]) return false;
  }
  return true;
}

bool list_sorted_strsup(List<double> a) {
  if (a.length <= 1) return true;
  double s = a[0];
  for (int i = 1; i < a.length; i++) {
    if (s >= a[i]) return false;
    s = a[i];
  }
  return true;
}

bool list_sorted_sup(List<double> a) {
  if (a.length <= 1) return true;
  double s = a[0];
  for (int i = 1; i < a.length; i++) {
    if (s > a[i]) return false;
    s = a[i];
  }
  return true;
}

bool list_sorted_strinf(List<double> a) {
  if (a.length <= 1) return true;
  double s = a[0];
  for (int i = 1; i < a.length; i++) {
    if (s <= a[i]) return false;
    s = a[i];
  }
  return true;
}

bool list_sorted_inf(List<double> a) {
  if (a.length <= 1) return true;
  double s = a[0];
  for (int i = 1; i < a.length; i++) {
    if (s < a[i]) return false;
    s = a[i];
  }
  return true;
}

bool azur_or(List<bool> a) {
  for (bool b in a) if (b) return true;
  return false;
}

bool azur_and(List<bool> a) {
  for (bool b in a) if (!b) return false;
  return true;
}

bool azur_xor(List<bool> a) {
  return azur_or(a) && !azur_and(a);
}
