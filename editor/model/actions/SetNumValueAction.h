#pragma once

#include <QtCore/QUuid>

#include "../Value.h"
#include "Action.h"

namespace AxiomModel {

    class SetNumValueAction : public Action {
    public:
        SetNumValueAction(const QUuid &uuid, NumValue beforeVal, NumValue afterVal, ModelRoot *root);

        static std::unique_ptr<SetNumValueAction> create(const QUuid &uuid, NumValue beforeVal, NumValue afterVal,
                                                         ModelRoot *root);

        static std::unique_ptr<SetNumValueAction> deserialize(QDataStream &stream, ModelRoot *root);

        void serialize(QDataStream &stream) const override;

        void forward(bool first, MaximCompiler::Transaction *transaction) override;

        void backward(MaximCompiler::Transaction *transaction) override;

    private:
        QUuid uuid;
        NumValue beforeVal;
        NumValue afterVal;
    };
}
