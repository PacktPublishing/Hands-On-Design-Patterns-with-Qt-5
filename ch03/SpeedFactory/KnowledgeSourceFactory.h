#ifndef KNOWLEDGESOURCEFACTORY_H
#define KNOWLEDGESOURCEFACTORY_H

class KnowledgeSource;
class Blackboard;

class KnowledgeSourceFactory
{
public:
    KnowledgeSourceFactory();
    virtual ~KnowledgeSourceFactory() = default;

    virtual KnowledgeSource *createProduct(Blackboard *a_blackboard) = 0;
};

#endif // KNOWLEDGESOURCEFACTORY_H
