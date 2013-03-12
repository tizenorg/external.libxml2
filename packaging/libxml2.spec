Summary: Library providing XML and HTML support
Name: libxml2
Version: 2.7.8
Release: 8.5.1
License: MIT
Group: System/Libraries
Source: ftp://xmlsoft.org/libxml2/libxml2-%{version}.tar.gz
BuildRequires: zlib-devel 
BuildRequires: python-devel
BuildRequires: python
BuildRequires: python-xml
URL: http://xmlsoft.org/

%description 
This library allows to manipulate XML files. It includes support 
to read, modify and write XML and HTML files. There is DTDs support
this includes parsing and validation even with complex DtDs, either
at parse time or later once the document has been modified. The output
can be a simple SAX stream or and in-memory DOM like representations.
In this case one can use the built-in XPath and XPointer implementation
to select subnodes or ranges. A flexible Input/Output mechanism is
available, with existing HTTP and FTP modules and combined to an
URI library.

%package devel
Summary: Libraries, includes, etc. to develop XML and HTML applications
Group: Development/Libraries
Requires: libxml2 = %{version}-%{release}
Requires: zlib-devel
Requires: python-devel
Requires: pkgconfig

%description devel
Libraries, include files, etc you can use to develop XML applications.
This library allows to manipulate XML files. It includes support 
to read, modify and write XML and HTML files. There is DTDs support
this includes parsing and validation even with complex DtDs, either
at parse time or later once the document has been modified. The output
can be a simple SAX stream or and in-memory DOM like representations.
In this case one can use the built-in XPath and XPointer implementation
to select subnodes or ranges. A flexible Input/Output mechanism is
available, with existing HTTP and FTP modules and combined to an
URI library.

%package python
Summary: Python bindings for the libxml2 library
Group: Development/Libraries
Requires: libxml2 = %{version}
Requires: %{_libdir}/python%{python_version}

%description python
The libxml2-python package contains a module that permits applications
written in the Python programming language to use the interface
supplied by the libxml2 library to manipulate XML files.

This library allows to manipulate XML files. It includes support
to read, modify and write XML and HTML files. There is DTDs support
this includes parsing and validation even with complex DTDs, either
at parse time or later once the document has been modified.

%prep
%setup -q

%build
autoreconf
%configure
make #%{_smp_mflags}

%install
rm -fr %{buildroot}

%make_install

rm -f $RPM_BUILD_ROOT%{_libdir}/*.a
rm -fr $RPM_BUILD_ROOT%{_datadir}/doc/libxml2-python-2.7.8

# multiarch crazyness on timestamp differences or Makefile/binaries for examples
#touch -m --reference=$RPM_BUILD_ROOT/%{_includedir}/libxml2/libxml/parser.h $RPM_BUILD_ROOT/%{_bindir}/xml2-config
(cd doc/examples ; make clean ; rm -rf .deps Makefile)

%remove_docs

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%defattr(-, root, root)
%{_libdir}/lib*.so.*
%{_bindir}/xmllint
%{_bindir}/xmlcatalog


%files devel
%defattr(-, root, root)
%{_libdir}/lib*.so
#needed to build python
%{_libdir}/*.sh
%{_includedir}/*
%{_bindir}/xml2-config
%{_datadir}/aclocal/libxml.m4
%{_libdir}/pkgconfig/libxml-2.0.pc

%files python
%defattr(-, root, root)
%{python_sitelib}/drv_libxml2*
%{python_sitelib}/libxml2*
