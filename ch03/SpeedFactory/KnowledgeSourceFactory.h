#ifndef KNOWLEDGESOURCEFACTORY_H
#define KNOWLEDGESOURCEFACTORY_H

class KnowledgeSource;
class Blackboard;

template <class T>
class KnowledgeSourceFactory
{
public:
//    KnowledgeSourceFactory();
//    virtual ~KnowledgeSourceFactory() = default;

    static KnowledgeSource *createProduct(Blackboard *a_blackboard) {
        auto obj = new T;
        obj->setBlackboard(a_blackboard);
        return obj;
    }
};

#endif // KNOWLEDGESOURCEFACTORY_H
