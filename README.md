# RPC
Códigos en c, para aprender a programar en distribuido

Los programas se crearon en c desde linux ubuntu 20 con rpcgen

# Para el servidor se requiere copilar los archivos:
    $gcc _xdr.c, _srv.c, _server.c -o server
# Para el cliente:
    $gcc _xdr.c _client.c _clnt.c -o cliente

# ejecutar el cliente 
    $./cliente (localhost/ip) el resto de datos
