#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int num_girl;
    int lista_adj[1000];
    int tam_lista_adj;
}vertice;


void mostrar_tudo (vertice * vertices, int qtd_vertices);
void dfs(vertice * vertices, int qtd_vertices, int raiz);

int main()
{
    int qtd_vertices, qtd_arestas;
    int i,a,b,qtd_cc=0;
    vertice * vertices;
    scanf("%d %d",&qtd_vertices, &qtd_arestas);

    int *distancias;
    int qtd_girls;

    // printf("\n Quantidade de vertices: %d ",qtd_vertices);
    // printf("\n Quantidade de arestas: %d\n",qtd_arestas);

    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));

    for(i=0;i<qtd_arestas;i++)
    {
        scanf("%d %d",&a,&b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
        vertices[b].tam_lista_adj++;
    }
    scanf("%d",&qtd_girls);
    int garota = 0;
    for(i=0; i < qtd_girls; i++) {
        scanf("%d",&garota);
        vertices[garota].num_girl = garota;
    }

    for(i=1;i<=qtd_vertices;i++)
    {
        if (vertices[i].visitado==0)
        {
            dfs(vertices,qtd_vertices,i);
            qtd_cc++;
        }
    }

    printf("\n%d",qtd_cc);

    // dfs(vertices,qtd_vertices,1);

    return 0;
}


void mostrar_tudo (vertice * vertices, int qtd_vertices)
{
    int i,j;

    for(i=1;i<=qtd_vertices;i++)
    {
        printf("\n Vertice: %d",i);
        printf("\n Lista de adjacencias: ");

        for(j=0;j<vertices[i].tam_lista_adj;j++)
        {
            printf("%d ",vertices[i].lista_adj[j]);
        }
    }
}

void dfs(vertice * vertices, int qtd_vertices, int raiz)
{
    int i;
    if (vertices[raiz].visitado!=0)
    {
        return;
    }

    // printf("\n %d",raiz);
    vertices[raiz].visitado=1;

    for(i=0;i<vertices[raiz].tam_lista_adj;i++)
    {
        if (vertices[vertices[raiz].lista_adj[i]].num_girl == 0)
        {
            dfs(vertices,qtd_vertices,vertices[raiz].lista_adj[i]);
        }
    }
}