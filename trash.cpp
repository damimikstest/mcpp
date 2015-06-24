/*trash.cpp*/

/* Operator * */
Vector Vector::operator*(int scalar){
	/* NOTICE that the left operant must be of type Vector and right operand of type int */
	Vector *allocation = new Vector((*this));
	for(int i = 0; i < dim; i++) allocation->fields[i] = fields[i] * scalar;
	return *allocation;
}

/* Add a vector */
void Vector::operator+=(const Vector &ref){
	(*this) = (*this) + ref;
}
/* Substract a vector */
void Vector::operator-=(const Vector &ref){
	(*this) = (*this) - ref;
}
/* Multiplicate by scalar */
void Vector::operator*=(int scalar){
	(*this) = (*this) * scalar;
}



/* Overloaded logic operators */
/* Comparison - Is equal */
bool Vector::operator==(const Vector &ref){
	if(dim == ref.dim){
		for(int i = 0; i < dim; i++){
			if(fields[i] != ref.fields[i]) return FALSE;
		}
		return TRUE;
	} else return FALSE;
}
/* Difference - Is not equal */
bool Vector::operator!=(const Vector &ref){
	return !((*this) == ref);
}