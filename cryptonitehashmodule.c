// Copyright (c) 2017 The Sumokoin Projects
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <Python.h>
#include "cryptonite_hash.h"

#include <stdint.h>

static PyObject *cryptonite_hash(PyObject *self, PyObject *args)
{
	char *output;
	PyObject *value;
#if PY_MAJOR_VERSION >= 3
	PyBytesObject *input;
#else
	PyStringObject *input;
#endif
	int aes_ni_supported;
	
	if (!PyArg_ParseTuple(args, "Si", &input, &aes_ni_supported))
		return NULL;
	Py_INCREF(input);
	output = (char*)PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
	cryptonight_hash(output, (char *) PyBytes_AsString((PyObject*) input), aes_ni_supported);
#else
	cryptonight_hash(output, (char *) PyString_AsString((PyObject*) input), aes_ni_supported);
#endif
	Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
	value = Py_BuildValue("y#", output, 32);
#else
	value = Py_BuildValue("s#", output, 32);
#endif
	PyMem_Free(output);
	return value;
}

static PyObject *cryptonite_scanhash(PyObject *self, PyObject *args)
{
#if PY_MAJOR_VERSION >= 3
	PyBytesObject *input;
#else
	PyStringObject *input;
#endif
	int ret;
	uint32_t target;
	uint32_t max_nonce;
	uint64_t hashes_done;
	
	if (!PyArg_ParseTuple(args, "SII", &input, &target, &max_nonce))
		return NULL;
	
	Py_INCREF(input);
	
	hashes_done = 0x0ULL;
#if PY_MAJOR_VERSION >= 3
	ret = scanhash_cryptonight((char *)PyBytes_AsString((PyObject*)input), target, max_nonce, &hashes_done);
#else
	ret = scanhash_cryptonight((char *)PyString_AsString((PyObject*)input), target, max_nonce, &hashes_done);
#endif
	
	Py_DECREF(input);

#if PY_MAJOR_VERSION >= 3
	return Py_BuildValue(("OK"), ret ? Py_True : Py_False, hashes_done);
#else
	return Py_BuildValue(("OK"), ret ? Py_True : Py_False, hashes_done);
#endif
}


static PyObject *cpu_has_aes_in_supported(PyObject *self, PyObject *args)
{
	bool ret;
	ret = has_aes_ni();
	return Py_BuildValue("O", ret ? Py_True : Py_False);
}

static PyObject *cryptolite_hash(PyObject *self, PyObject *args)
{
	char *output;
	PyObject *value;
#if PY_MAJOR_VERSION >= 3
	PyBytesObject *input;
#else
	PyStringObject *input;
#endif
	int aes_ni_supported;

	if (!PyArg_ParseTuple(args, "Si", &input, &aes_ni_supported))
		return NULL;
	Py_INCREF(input);
	output = (char*)PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
	cryptolight_hash(output, (char *)PyBytes_AsString((PyObject*)input), aes_ni_supported);
#else
	cryptolight_hash(output, (char *)PyString_AsString((PyObject*)input), aes_ni_supported);
#endif
	Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
	value = Py_BuildValue("y#", output, 32);
#else
	value = Py_BuildValue("s#", output, 32);
#endif
	PyMem_Free(output);
	return value;
}

static PyObject *cryptolite_scanhash(PyObject *self, PyObject *args)
{
#if PY_MAJOR_VERSION >= 3
	PyBytesObject *input;
#else
	PyStringObject *input;
#endif
	int ret;
	uint32_t target;
	uint32_t max_nonce;
	uint64_t hashes_done;

	if (!PyArg_ParseTuple(args, "SII", &input, &target, &max_nonce))
		return NULL;

	Py_INCREF(input);

	hashes_done = 0x0ULL;
#if PY_MAJOR_VERSION >= 3
	ret = scanhash_cryptolight((char *)PyBytes_AsString((PyObject*)input), target, max_nonce, &hashes_done);
#else
	ret = scanhash_cryptolight((char *)PyString_AsString((PyObject*)input), target, max_nonce, &hashes_done);
#endif

	Py_DECREF(input);

#if PY_MAJOR_VERSION >= 3
	return Py_BuildValue(("OK"), ret ? Py_True : Py_False, hashes_done);
#else
	return Py_BuildValue(("OK"), ret ? Py_True : Py_False, hashes_done);
#endif
}


static PyMethodDef CryptoniteMethods[] = {
	{ "cryptonite_hash", cryptonite_hash, METH_VARARGS, "Hash with cryptonight algorithm" },
	{ "cryptolite_hash", cryptolite_hash, METH_VARARGS, "Hash with cryptonight-light algorithm" },
	{ "cpu_has_aes_in_supported", cpu_has_aes_in_supported, METH_VARARGS, "Check if CPU supports AES-NI" },
	{ "cryptonite_scanhash", cryptonite_scanhash, METH_VARARGS, "Cryptonight scan for valid hash" },
	{ "cryptolite_scanhash", cryptolite_scanhash, METH_VARARGS, "Cryptonight-lite scan for valid hash" },
	{ NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef CryptoniteModule = {
	PyModuleDef_HEAD_INIT,
	"cryptonite_hash",
	"...",
	-1,
	CryptoniteMethods
};

PyMODINIT_FUNC PyInit_cryptonite_hash(void) {
	return PyModule_Create(&CryptoniteModule);
}

#else

PyMODINIT_FUNC initcryptonite_hash(void) {
	(void)Py_InitModule("cryptonite_hash", CryptoniteMethods);
}
#endif
