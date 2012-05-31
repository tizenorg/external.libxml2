Name:           libxml2
Version:        2.7.8
Release:        10
License:        MIT
Summary:        Library providing XML and HTML support
Url:            http://xmlsoft.org/
Group:          System/Libraries
Source:         ftp://xmlsoft.org/libxml2/libxml2-%{version}.tar.gz
Source1001: packaging/libxml2.manifest 
BuildRequires:  python-devel
BuildRequires:  python
BuildRequires:  python-xml
BuildRequires:  zlib-devel

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
Summary:        Libraries, includes, etc
Group:          Development/Libraries
Requires:       libxml2 = %{version}
Requires:       pkgconfig
Requires:       python-devel
Requires:       zlib-devel

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
Summary:        libxml2 Python bindings
Group:          Development/Libraries
Requires:       %{name} = %{version}

%description python
The libxml2-python package contains a module that permits applications
written in the Python programming language to use the interface
supplied by the libxml2 library to manipulate XML files.

%prep
%setup -q

%build
cp %{SOURCE1001} .
autoreconf
%configure
make 

%install
%make_install

rm -f %{buildroot}%{_libdir}/*.a
rm -fr %{buildroot}%{_datadir}/doc/libxml2-python-2.7.8

(cd doc/examples ; make clean ; rm -rf .deps Makefile)

%remove_docs

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%manifest libxml2.manifest
%{_libdir}/lib*.so.*
%{_bindir}/xmllint
%{_bindir}/xmlcatalog

%files devel
%manifest libxml2.manifest
%{_libdir}/lib*.so
#needed to build python
%{_libdir}/*.sh
%{_includedir}/*
%{_bindir}/xml2-config
%{_datadir}/aclocal/libxml.m4
%{_libdir}/pkgconfig/libxml-2.0.pc

%files python
%manifest libxml2.manifest
%{python_sitelib}/drv_libxml2*
%{python_sitelib}/libxml2*
